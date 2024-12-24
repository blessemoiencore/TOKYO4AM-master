#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    wait(0.02,sec);
  }
}
void setGrab(bool value) {
  grab.set(!value);
}


//fixed this false is now true //fixed
void RB_RUSH(){
odom_constants();
conveyor.setVelocity(100, percent);
intake.setVelocity(100, percent);
chassis.set_coordinates(0,0,0);

//grab mogo
chassis.drive_distance(-5, 0);//can change settle time per movement after two more commas
chassis.turn_to_angle(335, 5.5);
chassis.drive_distance(-33, 335);
grab.set(true);
wait(.2, sec);
//score preload
conveyor.spinFor(.5, sec);
//score first ring
chassis.drive_distance(5, 335);
chassis.turn_to_angle(270, 5.5);
intake.spin(forward);
conveyor.spin(forward);
chassis.drive_distance(17, 270);
//second ring
chassis.drive_distance(-7, 270);
chassis.turn_to_angle(205, 5.5);
chassis.drive_distance(11, 205);
wait(.4, sec);
//third ring
chassis.drive_distance(-4, 205);
chassis.turn_to_angle(230, 5.5);
chassis.drive_distance(8, 230);
wait(.9, sec);
//ladder
lift.spinToPosition(-140,degrees,false);
chassis.drive_distance(-27, -90);




}
//fixed
void rednegative(){
  
odom_constants();
conveyor.setVelocity(100,percent);
intake.setVelocity(100,percent);
chassis.set_coordinates(0,0,0);


//mogo
chassis.drive_distance(-14, 0);
chassis.turn_to_angle(40);
chassis.drive_distance(-25, 40);
grab.set(true);
wait(.4, sec);
chassis.drive_distance(5, 40);
conveyor.spin(forward);
intake.spin(forward);
wait(.5, sec);
//ring 1
chassis.turn_to_angle(90);
chassis.drive_distance(15, 90);
wait(.7, sec);
//ring 2
chassis.turn_to_angle(175);
chassis.drive_distance(10, 175);
//ring 3
chassis.drive_distance(-4, 175);
chassis.turn_to_angle(145);
chassis.drive_distance(7, 145);
wait(.5, sec);
//lift.spinToPosition(-400,degrees,false);
//ladder
lift.spinToPosition(-140,degrees,false);
chassis.drive_distance(-26, 90);

}

//fixed for new clamp // fixed
void testaoqiRed() {
   odom_constants();
conveyor.setVelocity(100, percent);
intake.setVelocity(0, percent);
chassis.set_coordinates(0,0,-270);


//grabs first ring
chassis.turn_to_angle(-250);
chassis.drive_distance(7,-250,9,9);
intake.spinFor(reverse, 0.15, seconds);
wait(0.1,sec);
intake.spin(forward);
wait(.5, sec);
intake.stop();
chassis.drive_distance(-.5,-250);
conveyor.spinFor(forward,0.5,seconds);

//scores on wall stake
chassis.turn_to_angle(-338);
chassis.drive_distance(11,-338,10,12);
lift.spinToPosition(-775,degrees,true);

//grabs mogo
chassis.turn_to_angle(-335);
lift.spinToPosition(-350,degrees,false);
intake.spin(forward);
chassis.drive_distance(-35, -335);
grab.set(true);

//scores ring and goes to ladder
conveyor.spin(forward);
wait(0.7,seconds);
chassis.turn_to_angle(-81);
chassis.drive_distance(20, -81);
wait(.7,sec);
chassis.drive_distance(-33, -75);
wait(0.2,sec);

}


//fixed for new clamp //fixed //x
void testaoqi() {
  odom_constants();
conveyor.setVelocity(100, percent);
intake.setVelocity(0, percent);
chassis.set_coordinates(0,0,270);

//grabs first ring
chassis.turn_to_angle(250);
chassis.drive_distance(6.4,250);
intake.spinFor(reverse, 0.1, seconds);
wait(0.1,sec);
intake.spin(forward);
wait(.5, sec);
intake.stop();
conveyor.spinFor(forward,0.5,seconds);

//scores on wall stake
chassis.turn_to_angle(338);
chassis.drive_distance(11);
lift.spinToPosition(-775,degrees,true);

//goes to second mogo
chassis.turn_to_angle(335);
lift.spinToPosition(-350,degrees,false);
intake.spin(forward);
chassis.drive_distance(-37, 335);
grab.set(true);

//loads ring and goes for ladder
conveyor.spin(forward);
wait(0.5,seconds);
chassis.turn_to_angle(81);
chassis.drive_distance(20, 81);
wait(.7,sec);
//lift.spinToPosition(-145,degrees,false);
chassis.drive_distance(-36, 80);
wait(0.2,sec);

}

void practice(){
  odom_constants();
  chassis.turn_timeout = 1500;
  
  //first stake
    chassis.set_coordinates(0,0,0);
    chassis.drive_distance(-1.5);
    chassis.turn_to_angle(35, 5.5);
    conveyor.setVelocity(100, percent);
    intake.setVelocity(100, percent);
    chassis.drive_distance(-14, 35);
    grab.set(true);
     wait(.1, seconds);
      conveyor.spin(forward);
    chassis.turn_to_angle(180, 5.5);
     
     //preload scored
   intake.spin(forward);
    
  //second ring
    chassis.drive_distance(20.5, 180);
    wait(.1, seconds);
    chassis.turn_to_angle(270, 5.5);
    
    //third ring
   chassis.drive_distance(20, 270);
   wait(.5, seconds);
   chassis.drive_distance(1, 270);
    chassis.drive_distance(-1, 270);
   chassis.turn_to_angle(360, 5.5);
   
   //fourth ring
    chassis.drive_distance(18, 360);
    wait(.5, seconds);
    //fifth ring
    chassis.drive_distance(10, 360);
     wait(1, seconds);
     conveyor.spinFor(reverse, .3, seconds);
     conveyor.spin(forward);
    chassis.drive_distance(-10, 360);
    wait(.3, seconds);
     //sixth/last ring scored
    chassis.turn_to_angle(287, 5.5);
     
    chassis.drive_distance(9, 287);
     wait(.25, seconds);
     //mobile goal in corner
    chassis.turn_to_angle(160, 5.5);
    wait(.3, seconds);
    conveyor.spinFor(reverse,.2,seconds);
    chassis.drive_distance(-12, 160);
    wait(.1, seconds);
    grab.set(false);
     wait(.1, seconds);
  chassis.drive_distance(6, 160);
  wait(.1, seconds);
  chassis.turn_to_angle(270, 5.5);
   //second stake
   chassis.drive_distance(-69, 270);
   grab.set(true);
   wait(.1, seconds);
   chassis.drive_distance(4);
    intake.spin(forward);
    conveyor.spin(forward);
    
    //wall
    chassis.turn_to_angle(180, 5.5);
    chassis.drive_distance(-11, 180);
    // first ring, stake 2
    conveyor.spin(forward);
     chassis.drive_distance(30 , 180);
    wait(.5, seconds);
    //second ring, stake 2
   chassis.turn_to_angle(115, 5.5);
  chassis.drive_distance(35, 115);
  wait(.2, seconds);
  //third ring, stake 2
   chassis.turn_to_angle(90, 5.5);
  chassis.drive_distance(-7, 90);
  chassis.turn_to_angle(0, 5.5);
 chassis.drive_distance(24, 0);
  wait(.7, seconds);
  // fourth ring, second stake
  chassis.drive_distance(15, 0);
  wait(.7, seconds);
  // fifth ring, second stake
chassis.drive_distance(7.55, 0);
// sixth ring, second stake
chassis.turn_to_angle(90, 5.5);
chassis.drive_distance(-5, 90);
chassis.turn_to_angle(0, 5.5);
chassis.drive_distance(-9, 0);
chassis.turn_to_angle(90, 5.5);
chassis.drive_distance(8, 90);
wait(.5, seconds);
// score stake
chassis.turn_to_angle(220, 5.5);
conveyor.spinFor(reverse,.5,seconds);
chassis.drive_distance(-15, 220);
grab.set(false);
wait(.2, seconds);
chassis.drive_distance(13, 220);
//
chassis.turn_to_angle(180, 5.5);
conveyor.setVelocity(100, percent);
intake.setVelocity(100, percent);
intake.spin(forward);


chassis.drive_distance(50, 180);
chassis.turn_to_angle(210, 5.5);
chassis.drive_distance(22.5, 210);

chassis.turn_to_angle(60, 5.5);
chassis.drive_distance(-25, 60);
grab.set(true);
wait(.1, seconds);
conveyor.spin(forward);

chassis.turn_to_angle(90, 5.5);
chassis.drive_distance(45, 90);
wait(.3, seconds);
chassis.drive_distance(8, 90);
chassis.turn_to_angle(300, 5.5);
chassis.drive_distance(-20, 300);
grab.set(false);
wait(.1, seconds);
chassis.drive_distance(20, 300);
chassis.turn_to_angle(70, 5.5);
chassis.drive_distance(-98, 70);
}





 void OpticalTest() {
odom_constants();
conveyor.setVelocity(70, percent);
intake.setVelocity(100, percent);
chassis.set_coordinates(0,0,0);
//ColorTest(Optical1.hue());
//Optical.setLight(ledState::on);
lift.spinTo(-140,deg,true);
//conveyor.spin(fwd);

//do this intead of a task
//works optical sensor just isnt registering in the code
while (true) {
 if (Optical.hue() > 230 && Optical.hue() < 240) {
  vex::task::sleep(200);
  conveyor.stop();
  lift.spinTo(-400,deg,true);
  vex::task::sleep(1);
  lift.spinTo(0,deg,true);
}


 if (Optical.hue() <= 20 || Optical.hue() >= 320) {
  lift.spinTo(-140,deg,true);
  conveyor.setVelocity(20,percent);
  vex::task::sleep(430);
  conveyor.stop();
lift.spinTo(-800,deg,true);
vex::task::sleep(1);
lift.spinTo(0,deg,true);
 }

}
 };



void testDrive() {
  //vex::task::skibidiMcgee(opticalDetect);

  odom_constants();
  conveyor.setVelocity(65, percent);
  intake.setVelocity(100, percent);
  chassis.set_coordinates(0,0,0);
  lift.spinTo(-140,deg);
  chassis.drive_distance(-6);

  //try out "lead"; lower lead means less curve; high lead big curve
  //check for imu vibration
  //setback is just offset
  chassis.drive_to_pose(1,2,3);
  //waitUntil(intake.spin)



  

}


