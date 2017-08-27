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

 function: highlevel encoder setup struct separated out for vorbisenc clarity

 ********************************************************************/

typedef struct highlevel_byblocktype {
  FPTYPE tone_mask_setting;
  FPTYPE tone_peaklimit_setting;
  FPTYPE noise_bias_setting;
  FPTYPE noise_compand_setting;
} highlevel_byblocktype;

typedef struct highlevel_encode_setup {
  int   set_in_stone;
  const void *setup;
  FPTYPE base_setting;

  FPTYPE impulse_noisetune;

  /* bitrate management below all settable */
  float  req;
  int    managed;
  long   bitrate_min;
  long   bitrate_av;
  FPTYPE bitrate_av_damp;
  long   bitrate_max;
  long   bitrate_reservoir;
  FPTYPE bitrate_reservoir_bias;

  int impulse_block_p;
  int noise_normalize_p;
  int coupling_p;

  FPTYPE stereo_point_setting;
  FPTYPE lowpass_kHz;
  int    lowpass_altered;

  FPTYPE ath_floating_dB;
  FPTYPE ath_absolute_dB;

  FPTYPE amplitude_track_dBpersec;
  FPTYPE trigger_setting;

  highlevel_byblocktype block[4]; /* padding, impulse, transition, long */

} highlevel_encode_setup;
