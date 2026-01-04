#pragma once

#include <array>
#include <vector>

struct ModuleConfig {
  // Steper motor config
  float stepper_motor_steps_per_rev;
  float stepper_motor_gear_ratio;
  float stepper_motor_max_velocity;
  float stepper_motor_min_velocity;
  bool stepper_motor_reverse;
  bool stepper_motor_enable_reversed;
  uint32_t stepper_motor_timer_prescaler;

  // Encoder pos arm
  float encoder_arm_offset;
  bool encoder_arm_reverse;
  float encoder_arm_dead_zone_correction_angle;
  uint16_t encoder_arm_velocity_sample_amount;

  // Encoder pos motor
  float encoder_motor_offset;
  bool encoder_motor_reverse;
  float encoder_motor_dead_zone_correction_angle;
  uint16_t encoder_motor_velocity_sample_amount;
  bool encoder_motor_enable;

  // pid config
  float pid_p;
  float pid_i;
  float pid_d;

  //--------------------Movement config

  /// @brief Maximum velocity of the arm
  float movement_max_velocity;
  /// @brief upper limit position of the arm
  float movement_limit_lower;
  /// @brief lower limit position of the arm
  float movement_limit_upper;
  uint8_t movement_control_mode;
  float movement_max_acceleration;
};