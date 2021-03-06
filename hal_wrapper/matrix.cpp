#include <nan.h>
#include "matrix.h"
#include "drivers/everloop.h"
#include "drivers/gpio.h"
#include "drivers/info.h"
#include "drivers/sensors/sensors.h"

// Declare bus for MATRIX hardware communication
matrix_hal::MatrixIOBus bus;
// Initialize MATRIX bus
bool busReady = bus.Init();

// Module initialization logic
NAN_MODULE_INIT(Initialize){
  // Initialize MATRIX BUS
  if (!bus.Init()) return Nan::ThrowError(Nan::New("MATRIX HAL BUS: NOT INITIALIZED!").ToLocalChecked());
    // Export function that returns LED object
    NAN_EXPORT(target, led);

    // Export function that returns GPIO object
    NAN_EXPORT(target, gpio);
    
    // Export function that returns Sensor objects
    NAN_EXPORT(target, imu);
    NAN_EXPORT(target, humidity);
    NAN_EXPORT(target, pressure);
    NAN_EXPORT(target, uv);

    // Export function that returns Device Info object
    NAN_EXPORT(target, info);
}

// Create the module called "addon" and initialize it with `Initialize` function (created with NAN_MODULE_INIT macro)
NODE_MODULE(addon, Initialize);