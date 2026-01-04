#pragma once

#include <cstdint>


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


/// @brief struct for the error data that represents the state of the system
/// Max amount of errors is equal to max length of the CAN frame so 8 x 8 = 64 (max)
/// The errors are represented as bool values
/// 0 - no error
/// 1 - error
/// you can retrieve the amount of errors by calling get_amount_of_errors()
class ErrorData {
public:
  ErrorData() = default;
  // temperature errors
  bool temp_engine_overheating       = false;
  bool temp_driver_overheating       = false;
  bool temp_board_overheating        = false;
  bool temp_engine_sensor_disconnect = false;
  bool temp_driver_sensor_disconnect = false;
  bool temp_board_sensor_disconnect  = false;

  // encoder errors
  bool encoder_arm_disconnect   = false;
  bool encoder_motor_disconnect = false;

  // board errors
  bool baord_overvoltage  = false;
  bool baord_undervoltage = false;

  // can errors
  bool can_disconnected = false;
  bool can_error        = false;

  // other errors
  bool controler_motor_limit_position = false;

  /// @brief get the amount of errors
  /// @return the amount of errors
  unsigned int get_amount_of_errors() const;
};