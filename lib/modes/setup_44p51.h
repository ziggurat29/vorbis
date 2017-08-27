/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2010             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: toplevel settings for 44.1/48kHz 5.1 surround modes

 ********************************************************************/

#include "residue_44p51.h"

static const FPTYPE rate_mapping_44p51[12]={
  FPCONST(14000.0),FPCONST(20000.0),FPCONST(28000.0),FPCONST(38000.0),FPCONST(46000.0),FPCONST(54000.0),
  FPCONST(75000.0),FPCONST(96000.0),FPCONST(120000.0),FPCONST(140000.0),FPCONST(180000.0),FPCONST(240001.0)
};

static const ve_setup_data_template ve_setup_44_51={
  11,
  rate_mapping_44p51,
  quality_mapping_44,
  6,
  40000,
  70000,

  blocksize_short_44,
  blocksize_long_44,

  _psy_tone_masteratt_44,
  _psy_tone_0dB,
  _psy_tone_suppress,

  _vp_tonemask_adj_otherblock,
  _vp_tonemask_adj_longblock,
  _vp_tonemask_adj_otherblock,

  _psy_noiseguards_44,
  _psy_noisebias_impulse,
  _psy_noisebias_padding,
  _psy_noisebias_trans,
  _psy_noisebias_long,
  _psy_noise_suppress,

  _psy_compand_44,
  _psy_compand_short_mapping,
  _psy_compand_long_mapping,

  {_noise_start_short_44,_noise_start_long_44},
  {_noise_part_short_44,_noise_part_long_44},
  _noise_thresh_44,

  _psy_ath_floater,
  _psy_ath_abs,

  _psy_lowpass_44,

  _psy_global_44,
  _global_mapping_44,
  _psy_stereo_modes_44,

  _floor_books,
  _floor,
  3,
  _floor_mapping_44,

  _mapres_template_44_51
};
