#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT20, ratio6_1, true);
motor leftMotorB = motor(PORT19, ratio6_1, false);
motor leftMotorC = motor(PORT18, ratio6_1,true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT9, ratio6_1, false);
motor rightMotorB = motor(PORT7, ratio6_1, true);
motor rightMotorC = motor(PORT8, ratio6_1,false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);
inertial DrivetrainInertial = inertial(PORT17);
controller Controller1 = controller(primary);
motor conveyor = motor(PORT3, ratio18_1, true);
motor intake = motor(PORT2, ratio18_1, false);
motor lift = motor(PORT5,ratio6_1, true );
digital_out grab = digital_out(Brain.ThreeWirePort.H);
optical Optical = optical(PORT1);

digital_out intakeLift = digital_out(Brain.ThreeWirePort.A); //subject to change
digital_out doink = digital_out(Brain.ThreeWirePort.B);

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:





 void ColorTest(int hue) {


/* while(int(Optical.hue()) < 220 && int(Optical.hue()) > 165 ){
    grab.set(true);
  }

  */
 
  /*
  int x = 1;
  while (x > 0) {
  if (hue > 165 && hue < 230) {
  lift.spinTo(-800,degrees,false);
  }
  else if (hue > 330 || hue < 30) 
 {
  grab.set(true);
 }
  }
  */
}




//bool doTask = true; //turn off during driver control; set to true during auton and false during usercontrol




//must use int type for tasks

/* void ColorSort() {
  while (doTask) {
  if (ColorTest(Optical1.hue()) == 'b') {
    lift.spinTo(-800,degrees,false);
  }
  else {
    lift.spinTo(0,degrees,false);
  }

  vex::task::sleep(20); //prevents wasted resources
  }
  
}
*/



void vexcodeInit( void ) {
  // nothing to initialize
}

//Colors

