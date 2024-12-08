using namespace vex;

extern brain Brain;
// VEXcode devices
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;
extern motor conveyor;
extern controller Controller1;
extern inertial DrivetrainInertial;
extern digital_out grab;
extern motor intake;
extern motor lift;
extern optical Optical;



//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:



void  vexcodeInit( void );