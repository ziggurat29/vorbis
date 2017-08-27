/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2009             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: toplevel settings for 32kHz

 ********************************************************************/

static const FPTYPE rate_mapping_32[12]={
  FPCONST(18000.0),FPCONST(28000.0),FPCONST(35000.0),FPCONST(45000.0),FPCONST(56000.0),FPCONST(60000.0),
  FPCONST(75000.0),FPCONST(90000.0),FPCONST(100000.0),FPCONST(115000.0),FPCONST(150000.0),FPCONST(190000.0),
};

static const FPTYPE rate_mapping_32_un[12]={
  FPCONST(30000.0),FPCONST(42000.0),FPCONST(52000.0),FPCONST(64000.0),FPCONST(72000.0),FPCONST(78000.0),
  FPCONST(86000.0),FPCONST(92000.0),FPCONST(110000.0),FPCONST(120000.0),FPCONST(140000.0),FPCONST(190000.0),
};

static const FPTYPE _psy_lowpass_32[12]={
  FPCONST(12.3),FPCONST(13.0),FPCONST(13.0),FPCONST(14.0),FPCONST(15.0),FPCONST(99.0),FPCONST(99.0),FPCONST(99.0),FPCONST(99.0),FPCONST(99.0),FPCONST(99.0),FPCONST(99.0)
};

static const ve_setup_data_template ve_setup_32_stereo={
  11,
  rate_mapping_32,
  quality_mapping_44,
  2,
  26000,
  40000,

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

  _psy_lowpass_32,

  _psy_global_44,
  _global_mapping_44,
  _psy_stereo_modes_44,

  _floor_books,
  _floor,
  2,
  _floor_mapping_44,

  _mapres_template_44_stereo
};

static const ve_setup_data_template ve_setup_32_uncoupled={
  11,
  rate_mapping_32_un,
  quality_mapping_44,
  -1,
  26000,
  40000,

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

  _psy_lowpass_32,

  _psy_global_44,
  _global_mapping_44,
  NULL,

  _floor_books,
  _floor,
  2,
  _floor_mapping_44,

  _mapres_template_44_uncoupled
};
