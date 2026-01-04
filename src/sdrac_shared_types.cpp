#include "sdrac_shared_types.hpp"
#include <cstdint>

unsigned int ErrorData::get_amount_of_errors() const {
  return (uint8_t)temp_engine_overheating + (uint8_t)temp_driver_overheating + (uint8_t)temp_board_overheating +
         (uint8_t)temp_engine_sensor_disconnect + (uint8_t)temp_driver_sensor_disconnect +
         (uint8_t)temp_board_sensor_disconnect + (uint8_t)encoder_arm_disconnect +
         (uint8_t)encoder_motor_disconnect + (uint8_t)baord_overvoltage + (uint8_t)baord_undervoltage +
         (uint8_t)can_disconnected + (uint8_t)can_error + (uint8_t)controler_motor_limit_position;
}