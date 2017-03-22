/* ------- file: -------------------------- geometry.h --------------

       Version:       rh2.0, 3-D plane-parallel
       Author:        Tiago Pereira (tiago.pereira@nasa.gov)
       Last modified: Wed Dec 22 16:44:00 2010 --

       --------------------------                      ----------RH-- */


#ifndef __IO_H__
#define __IO_H__

#include <hdf5.h>
#include <hdf5_hl.h>

/* Definitions for readj_p */
#define  J_FILE_TEMPLATE "%s.hdf5"

/* Definitions for readAtmos_hdf5 */
#define  TEMP_NAME  "temperature"
#define  VTURB_NAME "velocity_turbulent"
#define  VZ_NAME    "velocity_z"
#define  NE_NAME    "electron_density"
#define  NH_NAME    "hydrogen_populations"
#define  Z_NAME     "z"
#define  BX_NAME    "B_x"
#define  BY_NAME    "B_y"
#define  BZ_NAME    "B_z"
#define  SNAPNAME   "snapshot_number"
#define  BBOT_NAME  "boundary_bottom"
#define  BTOP_NAME  "boundary_top"

/* Definitions for background_p */
#define  FILE_EXT ".dat"

/* Definitions for the ray file */
#define RAY_FILE     "output/output_ray.hdf5"
#define INT_NAME    "intensity"
#define FLUX_NAME   "flux"
#define STOKES_Q    "stokes_Q"
#define STOKES_U    "stokes_U"
#define STOKES_V    "stokes_V"
#define WAVE_NAME   "wavelength"
#define WAVE_SEL     "wavelength_selected"
#define WAVE_SEL_IDX "wavelength_indices"
#define CHI_NAME     "chi"
#define S_NAME       "source_function"
#define TAU1_NAME    "tau_one_height"
#define CHI_L_NAME   "chi_line"
#define ETA_L_NAME   "eta_line"
#define CHI_C_NAME   "chi_continuum"
#define ETA_C_NAME   "eta_continuum"
#define SCA_C_NAME   "scattering" // This is actually sca*J

/* Definitions for the input data file */
#define INPUTDATA_FILE "output/output_indata.hdf5"
#define XNUM_NAME      "xnum"
#define YNUM_NAME      "ynum"
#define TASK_MAP       "task_map"
#define TASK_NUMBER    "task_number"
#define ITER_NAME      "iterations"
#define CONV_NAME      "convergence"
#define DM_NAME        "delta_max"
#define DMH_NAME       "delta_max_history"
#define ZC_NAME        "z_cut"
#define NTASKS         "ntasks"
#define HOSTNAME       "hostname"
#define START_TIME     "starting_time"
#define FINISH_TIME    "finish_time"


/* Definitions for the Aux file */
#define ARR_STRLEN  30
#define AUX_FILE    "output/output_aux.hdf5"
#define POP_NAME    "populations"
#define POPLTE_NAME "populations_LTE"
#define RIJ_L_NAME  "Rij_line"
#define RJI_L_NAME  "Rji_line"
#define RIJ_C_NAME  "Rij_continuum"
#define RJI_C_NAME  "Rji_continuum"
#define EM_NAME     "energy_matrix"
#define COLL_NAME   "collision_rates"
#define DAMP_NAME   "damping"
#define VBROAD_NAME "broadening_velocity"
#define NW_AD_NAME  "nwave_angle_dep"
#define NW_AI_NAME  "nwave_angle_ind"
#define CHI_AI_NAME "chi_angle_ind"
#define CHI_AD_NAME "chi_angle_dep"
#define ETA_AI_NAME "eta_angle_ind"
#define ETA_AD_NAME "eta_angle_dep"
#define WAVET_NAME  "wavelength_nm"
#define WAVE_AD_IDX_NAME "wave_angle_dep_indices"
#define WAVE_AI_IDX_NAME "wave_angle_ind_indices"


#define STOPFILE_TEMPLATE "scratch/STOP_FILE_p%d"

/* Log files buffer size (in bytes) */
#define BUFSIZ_MPILOG  52428800

/* For keeping the HDF5 file and variable IDs */
typedef struct {
  /* for the J file */
  int  j_ncid,            j_jlambda_var,     j_j20_var,          j_jgas_var;
  /* for the spectrum file*/
  int  spec_ncid,         spec_int_var,      spec_flux_var,     spec_wave_var,
       spec_stokes_u_var, spec_stokes_q_var, spec_stokes_v_var;
  /* for the input data file. Note: this HDF5 file has several groups */
  int  in_ncid,           in_input_ncid,     in_atmos_ncid,     in_mpi_ncid;
  int  in_atmos_T,        in_atmos_ne,       in_atmos_vz,       in_atmos_vt,
       in_atmos_Bx,       in_atmos_By,       in_atmos_Bz,       in_atmos_nh,
    /* in_atmos_B,        in_atmos_gB,       in_atmos_chiB,     in_atmos_nh, */
       in_atmos_ew,       in_atmos_ab,       in_atmos_eid,      in_atmos_mu,
       in_atmos_wmu,      in_atmos_z,        in_atmos_x,        in_atmos_y;
  int  in_mpi_xnum,       in_mpi_ynum,       in_mpi_tm,         in_mpi_tn,
       in_mpi_it,         in_mpi_conv,       in_mpi_dm,         in_mpi_dmh,
       in_mpi_ntsk,       in_mpi_host,       in_mpi_st,         in_mpi_ft,
       in_mpi_zc;
  /* for the aux file */
  int  aux_ncid,         *aux_atom_ncid,     aux_op_ncid,      *aux_atom_pop,
      *aux_atom_poplte,  *aux_atom_RijL,    *aux_atom_RjiL,    *aux_atom_RijC,
      *aux_atom_RjiC,    *aux_atom_coll,    *aux_atom_damp,    *aux_atom_vbroad,
      *aux_mol_ncid,     *aux_mol_pop,      *aux_mol_poplte,   *aux_mol_E,
      *aux_mol_vbroad,
       aux_op_chi_ai,     aux_op_chi_ad,     aux_op_eta_ai,     aux_op_eta_ad;
  /* for atom file positions */
  long *atom_file_pos;
  /* for the ray file */
  int  ray_ncid,          ray_nwave_sel,     ray_wave_var,      ray_int_var,
       ray_stokes_q_var,  ray_stokes_u_var,  ray_stokes_v_var,  ray_j_var, 
       ray_chi_l_var,     ray_eta_l_var,     ray_chi_c_var,     ray_eta_c_var,
       ray_sca_c_var,     ray_chi_var,       ray_S_var,        *ray_wave_idx,
       ray_tau1_var;
} IO_data;

typedef struct {
  double  **n, **nstar, **nv, **nvstar, **RijL, **RjiL, **RijC, **RjiC;
  float   *J,  *J20;
} IO_buffer;

/* Default fill value for HDF5 */
extern const float FILLVALUE;

#endif /* !__IO_H__ */

/* ---------------------------------------- io.h -------------------- */
