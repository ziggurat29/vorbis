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

 function: toplevel settings for 44.1/48kHz

 ********************************************************************/

#include "floor_all.h"
#include "residue_44.h"
#include "psych_44.h"

static const FPTYPE rate_mapping_44_stereo[12]={
  FPCONST(22500.0),FPCONST(32000.0),FPCONST(40000.0),FPCONST(48000.0),FPCONST(56000.0),FPCONST(64000.0),
  FPCONST(80000.0),FPCONST(96000.0),FPCONST(112000.0),FPCONST(128000.0),FPCONST(160000.0),FPCONST(250001.0)
};

static const FPTYPE quality_mapping_44[12]={
  FPCONST(-.1),FPCONST(.0),FPCONST(.1),FPCONST(.2),FPCONST(.3),FPCONST(.4),FPCONST(.5),FPCONST(.6),FPCONST(.7),FPCONST(.8),FPCONST(.9),FPCONST(1.0)
};

static const int blocksize_short_44[11]={
  512,256,256,256,256,256,256,256,256,256,256
};
static const int blocksize_long_44[11]={
  4096,2048,2048,2048,2048,2048,2048,2048,2048,2048,2048
};

static const FPTYPE _psy_compand_short_mapping[12]={
  FPCONST(0.5), FPCONST(1.0), FPCONST(1.0), FPCONST(1.3), FPCONST(1.6), FPCONST(2.0), FPCONST(2.0), FPCONST(2.0), FPCONST(2.0), FPCONST(2.0), FPCONST(2.0), FPCONST(2.0)
};
static const FPTYPE _psy_compand_long_mapping[12]={
  FPCONST(3.5), FPCONST(4.0), FPCONST(4.0), FPCONST(4.3), FPCONST(4.6), FPCONST(5.0), FPCONST(5.0), FPCONST(5.0), FPCONST(5.0), FPCONST(5.0), FPCONST(5.0), FPCONST(5.0)
};

static const FPTYPE _global_mapping_44[12]={
  /* 1., 1., 1.5, 2., 2., 2.5, 2.7, 3.0, 3.5, 4., 4. */
 FPCONST(0.0), FPCONST(1.0), FPCONST(1.0), FPCONST(1.5), FPCONST(2.0), FPCONST(2.0), FPCONST(2.5), FPCONST(2.7), FPCONST(3.0), FPCONST(3.7), FPCONST(4.0), FPCONST(4.0)
};

static const int _floor_mapping_44a[11]={
  1,0,0,2,2,4,5,5,5,5,5
};

static const int _floor_mapping_44b[11]={
  8,7,7,7,7,7,7,7,7,7,7
};

static const int _floor_mapping_44c[11]={
  10,10,10,10,10,10,10,10,10,10,10
};

static const int *_floor_mapping_44[]={
  _floor_mapping_44a,
  _floor_mapping_44b,
  _floor_mapping_44c,
};

static const ve_setup_data_template ve_setup_44_stereo={
  11,
  rate_mapping_44_stereo,
  quality_mapping_44,
  2,
  40000,
  50000,

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
  2,
  _floor_mapping_44,

  _mapres_template_44_stereo
};
