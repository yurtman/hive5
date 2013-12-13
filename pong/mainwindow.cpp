/* POINTS TO IMPROVE:       (x = don't know how yet, o = working on it)

            x- get the score to tally correctly
            x- set the right variables to global (ball, window, paddles, scores) nevermind.. apparently global variables are evil
            x- get the button to work
            x- instead of button, use keyboard inputs
            x- get reinitialisation to work
            o- make human like AI (only move when ball moves towards paddle and take into account bounces) getg rid of jump

//BEGIN LIST OF VARIABLES

    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_bottom = this->geometry().height();    //not bottom!! (not sure why)
    const int window_left = 0;
    const int window_right = this->geometry().width();      //not right!! (not sure why)
    const int window_width = this->geometry().width();
    const int window_height = this->geometry().height();
    const int window_center_x = (this->width()/2);
    const int window_center_y = (this->height()/2);

    //ball variables
    const int ball_dx = 1;
    const int ball_dy = 1;
    const int ball_top = this->ui->ball->geometry().top();
    const int ball_bottom = this->ui->ball->geometry().bottom();
    const int ball_left = this->ui->ball->geometry().left();
    const int ball_right = this->ui->ball->geometry().right();
    const int ball_width = this->ui->ball->geometry().width();
    const int ball_height = this->ui->ball->geometry().height();
    const int ball_center_x = ball_left + 0.5*ball_width;
    const int ball_center_y = ball_top + 0.5*ball_height;

    //left paddle variables
    const int leftpaddle_dy = 1;
    const int leftpaddle_top = this->ui->leftpaddle->geometry().top();
    const int leftpaddle_bottom = this->ui->leftpaddle->geometry().bottom();
    const int leftpaddle_left = this->ui->leftpaddle->geometry().left();
    const int leftpaddle_right = this->ui->leftpaddle->geometry().right();
    const int leftpaddle_width = this->ui->leftpaddle->geometry().width();
    const int leftpaddle_height = this->ui->leftpaddle->geometry().height();
    const int leftpaddle_center_x = leftpaddle_left + 0.5*leftpaddle_width;
    const int leftpaddle_center_y = leftpaddle_top + 0.5*leftpaddle_height;

    //right paddle variables
    const int rightpaddle_dy = 1;
    const int rightpaddle_top = this->ui->rightpaddle->geometry().top();
    const int rightpaddle_bottom = this->ui->rightpaddle->geometry().bottom();
    const int rightpaddle_left = this->ui->rightpaddle->geometry().left();
    const int rightpaddle_right = this->ui->rightpaddle->geometry().right();
    const int rightpaddle_width = this->ui->rightpaddle->geometry().width();
    const int rightpaddle_height = this->ui->rightpaddle->geometry().height();
    const int rightpaddle_center_x = rightpaddle_left + 0.5*rightpaddle_width;
    const int rightpaddle_center_y = rightpaddle_top + 0.5*rightpaddle_height;

    //player scores
    int P1score = 0;
    int P2score = 0;

//END LIST OF VARIABLES
*/

#include <iostream>
#include <cassert>
#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// set boolean to true so paddles go up and ball goes up left
    this->leftpaddle_up = true;
    this->rightpaddle_up = true;
    this->ball_direction_right = true;
    this->ball_direction_up = true;

// create a timer for the game
    QTimer * const timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timer()));
    timer->setInterval(5);
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//THIS HAPPENS WHEN THE TIMER RUNS
void MainWindow::timer()
{
    //set the stage
        this->fieldalign();
        //this->on_pushButton_clicked();

    //ball behaviour
        this->standardball();
        //this->reinitialise();

    //left paddle behaviour
        //this->AI_perfect_leftpaddle();    //perfect
        this->AI_human_leftpaddle();      //perfect human like
        //this->AI_simple_leftpaddle();       //simple up and down

    //right paddle behaviour
        this->AI_perfect_rightpaddle();     //perfect
        //this->AI_human_rightpaddle();     //perfect human like
        //this->AI_simple_rightpaddle();    //simple up and down
}


//SETTING THE STAGE
void MainWindow::fieldalign()
{
    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_height = this->geometry().height();
    const int window_center_x = (this->width()/2);

    //score variables
    const int leftscore_position = (0.9*window_center_x);
    const int rightscore_position = (1.1*window_center_x);

    //set the net to the center and adjust it's size
    ui->net->setGeometry(window_center_x, window_top, 1, window_height);

    //set the score positions relative to center
    this->ui->leftscore->setGeometry(
                leftscore_position - 30,                    //TODO: adjust this to more generic
                window_top + 40,                            //TODO: adjust this to more generic
                this->ui->leftscore->geometry().width(),
                this->ui->leftscore->geometry().height());

    this->ui->rightscore->setGeometry(
                rightscore_position,
                window_top + 40,                            //TODO: adjust this to more generic
                this->ui->rightscore->geometry().width(),
                this->ui->rightscore->geometry().height());

    //set the pushbutton relative to center
    this->ui->pushButton->setGeometry(
                window_center_x - (this->ui->pushButton->geometry().width()/2),
                window_top,
                this->ui->pushButton->geometry().width(),
                this->ui->pushButton->geometry().height());
}

//STANDARD BALL BEHAVIOUR
void MainWindow::standardball()
{
    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_bottom = this->geometry().height();    //not bottom!! (not sure why)
    const int window_left = 0;
    const int window_right = this->geometry().width();      //not right!! (not sure why)

    //ball variables
    const int ball_dx = 1;
    const int ball_dy = 1;
    const int ball_top = this->ui->ball->geometry().top();
    const int ball_bottom = this->ui->ball->geometry().bottom();
    const int ball_left = this->ui->ball->geometry().left();
    const int ball_right = this->ui->ball->geometry().right();
    const int ball_width = this->ui->ball->geometry().width();
    const int ball_height = this->ui->ball->geometry().height();

    //left paddle variables
    const int leftpaddle_top = this->ui->leftpaddle->geometry().top();
    const int leftpaddle_bottom = this->ui->leftpaddle->geometry().bottom();
    const int leftpaddle_right = this->ui->leftpaddle->geometry().right();

    //right paddle variables
    const int rightpaddle_top = this->ui->rightpaddle->geometry().top();
    const int rightpaddle_bottom = this->ui->rightpaddle->geometry().bottom();
    const int rightpaddle_left = this->ui->rightpaddle->geometry().left();

    //player scores
    int P1score = 0;
    int P2score = 0;

    //define boolean for increment calculation
    bool new_ball_direction_up = ball_direction_up;
    bool new_ball_direction_right = ball_direction_right;

    //if ball goes beyond top, change new_ball_direction_up to false
    if (ball_top - ball_dy < window_top)
        {
            new_ball_direction_up = false;
        }

    //if ball goes beyond bottom, change new_ball_direction_up to true
    if (ball_bottom + ball_dy > window_bottom)
        {
            new_ball_direction_up = true;
        }

    //if ball hits left paddle, change new_ball_direction_right to true
    if ((ball_left - ball_dx - leftpaddle_right == -1) && (ball_bottom > leftpaddle_top) && (ball_top < leftpaddle_bottom))
        {
            new_ball_direction_right = true;
        }

    //if ball hits right paddle, change new_ball_direction_right to false
    if ((ball_right + ball_dx - rightpaddle_left == 1)  && (ball_bottom > rightpaddle_top) && (ball_top < rightpaddle_bottom))
        {
            new_ball_direction_right = false;
        }

    //if ball goes beyond left, add score to P2 and reinitialise
    if (ball_left - ball_dx < window_left)
        {
            new_ball_direction_right = true;
            int P2newscore = P2score + 1;                   //add one to score
            this->ui->rightscore->setValue(P2newscore);     //display new score
            P2score = P2newscore;                           //save new score as score
            //this->reinitialise();                         //reinitialise  ???
        }
    //if ball goes beyond right, add score to P1 and reinitialise
    if (ball_right + ball_dx > window_right)
        {
            new_ball_direction_right = false;
            int P1newscore = P1score +1;                    //add 1 to score
            this->ui->leftscore->setValue(P1newscore);      //display new score
            P1score = P1newscore;                           //save newscore as score
            //this->ui->ball->setGeometry(100,100,20,20);   //reinitialise  ???
            //this->reinitialise();                         //reinitialise  ???
        }

    //let ball move in x direction
    int moveball_x = 1;                                     //define moveball_x and imitialise to random value
    if (new_ball_direction_right == true)
    {
        moveball_x = ball_left + ball_dx;
    }
    else
    {
        moveball_x = ball_left - ball_dx;
    }

    //let ball move in y direction
    int moveball_y = 1;
    if (new_ball_direction_up == true)
    {
        moveball_y = ball_top - ball_dy;
    }
    else
    {
        moveball_y = ball_top + ball_dy;
    }

    //set the ball coordinates to the new coordinates
    this->ui->ball->setGeometry(
                moveball_x,                         //x-cordinate
                moveball_y,                         //y-coordinate
                ball_width,                         //width
                ball_height);                       //height


    //store direction for next time
    ball_direction_up = new_ball_direction_up;
    ball_direction_right = new_ball_direction_right;
}

//SIMPLE LEFT PADDLE AI BEHAVIOUR
void MainWindow::AI_simple_leftpaddle()
{

    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_bottom = this->geometry().height();    //not bottom!! (not sure why)

    //left paddle variables
    const int leftpaddle_dy = 1;
    const int leftpaddle_top = this->ui->leftpaddle->geometry().top();
    const int leftpaddle_bottom = this->ui->leftpaddle->geometry().bottom();
    const int leftpaddle_width = this->ui->leftpaddle->geometry().width();
    const int leftpaddle_height = this->ui->leftpaddle->geometry().height();

    //define boolean of quantum step and initialise at current value
    bool new_leftpaddle_up = leftpaddle_up;

    //if left paddle hits top, go down
    if (leftpaddle_top - leftpaddle_dy < window_top)
    {
        new_leftpaddle_up = false;
    }

    //if right paddle hits bottom, go up
    if (leftpaddle_bottom + leftpaddle_dy > window_bottom)
    {
        new_leftpaddle_up = true;
    }

    //let left paddle move in y
    int move_leftpaddle = 1;
    if (new_leftpaddle_up == true)
    {
        move_leftpaddle = leftpaddle_top - leftpaddle_dy;
    }
    else
    {
        move_leftpaddle = leftpaddle_top + leftpaddle_dy;
    }

    //change left paddle coordinates to new coordinates
    this->ui->leftpaddle->setGeometry(
                this->ui->leftpaddle->geometry().x(),       //x coordinate
                move_leftpaddle,                            //y coordinate
                leftpaddle_width,                           //width
                leftpaddle_height);                         //height


    //store left paddle direction
    leftpaddle_up = new_leftpaddle_up;
}


//SIMPLE RIGHT PADDLE AI BEHAVIOUR
void MainWindow::AI_simple_rightpaddle()
{
    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_bottom = this->geometry().height();    //not bottom!! (not sure why)
    const int window_right = this->geometry().width();      //not right!! (not sure why)

    //right paddle variables
    const int rightpaddle_dy = 1;
    const int rightpaddle_top = this->ui->rightpaddle->geometry().top();
    const int rightpaddle_bottom = this->ui->rightpaddle->geometry().bottom();

    //define boolean of quantum step and initialise at current value
    bool new_rightpaddle_up = rightpaddle_up;

    //if right paddle hits top, go down
    if (rightpaddle_top - rightpaddle_dy < window_top)
    {
        new_rightpaddle_up = false;
    }

    //if right paddle hits bottom, go up
    if (rightpaddle_bottom + rightpaddle_dy > window_bottom)
    {
        new_rightpaddle_up = true;
    }

    //let right paddle move in y
    int move_rightpaddle = 1;
    if (new_rightpaddle_up == true)
    {
        move_rightpaddle = rightpaddle_top - rightpaddle_dy;
    }
    else
    {
        move_rightpaddle = rightpaddle_top + rightpaddle_dy;
    }

    //change right paddle coordinates to new coordinates
    this->ui->rightpaddle->setGeometry(
                window_right -70,                           //x coordinate
                move_rightpaddle,                           //y coordinate
                this->ui->rightpaddle->geometry().width(),  //width
                this->ui->rightpaddle->geometry().height()  //height
                );

    //store right paddle direction
    rightpaddle_up = new_rightpaddle_up;
}

//HUMAN-LIKE LEFT PADDLE AI BEHAVIOUR
void MainWindow::AI_human_leftpaddle()
{
    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_bottom = this->geometry().height();    //not bottom!! (not sure why)

    //ball variables
    const int ball_top = this->ui->ball->geometry().top();
    const int ball_height = this->ui->ball->geometry().height();
    const int ball_center_y = ball_top + 0.5*ball_height;

    //left paddle variables
    const int leftpaddle_left = this->ui->leftpaddle->geometry().left();
    const int leftpaddle_width = this->ui->leftpaddle->geometry().width();
    const int leftpaddle_height = this->ui->leftpaddle->geometry().height();

    //when ball is incoming, if not at edge of window, move left paddle with ball
    if ((ball_direction_right == false) && (ball_center_y > window_top + 0.5*leftpaddle_height) && (ball_center_y < (window_bottom - 0.5*leftpaddle_height)))
    {
        this->ui->leftpaddle->setGeometry(
                    leftpaddle_left,                        //x coordinate
                    ball_center_y - 0.5*leftpaddle_height,  //y coordinate
                    leftpaddle_width,                       //width
                    leftpaddle_height);                     //height
    }
}

//HUMAN-LIKE RIGHT PADDLE AI BEHAVIOUR
void MainWindow::AI_human_rightpaddle()
{
    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_bottom = this->geometry().height();    //not bottom!! (not sure why)
    const int window_right = this->geometry().width();      //not right!! (not sure why)

    //ball variables
    const int ball_top = this->ui->ball->geometry().top();
    const int ball_height = this->ui->ball->geometry().height();
    const int ball_center_y = ball_top + 0.5*ball_height;

    //right paddle variables
    const int rightpaddle_width = this->ui->rightpaddle->geometry().width();
    const int rightpaddle_height = this->ui->rightpaddle->geometry().height();

    //when ball is incoming, if not at edge of window, move right paddle with ball
    if ((ball_direction_right == false) && (ball_center_y > window_top + 0.5*rightpaddle_height) && (ball_center_y < (window_bottom - 0.5*rightpaddle_height)))
    {
        this->ui->rightpaddle->setGeometry(
                    window_right -70,                       //x coordinate
                    ball_center_y - 0.5*rightpaddle_height, //y coordinate
                    rightpaddle_width,                      //width
                    rightpaddle_height);                    //height
    }
}


//PERFECT LEFT PADDLE AI BEHAVIOUR
void MainWindow::AI_perfect_leftpaddle()
{
    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_bottom = this->geometry().height();    //not bottom!! (not sure why)

    //ball variables
    const int ball_top = this->ui->ball->geometry().top();
    const int ball_height = this->ui->ball->geometry().height();
    const int ball_center_y = ball_top + 0.5*ball_height;

    //left paddle variables
    const int leftpaddle_left = this->ui->leftpaddle->geometry().left();
    const int leftpaddle_width = this->ui->leftpaddle->geometry().width();
    const int leftpaddle_height = this->ui->leftpaddle->geometry().height();

    //if not at edge of window, move left paddle with ball
    if ((ball_center_y > window_top + 0.5*leftpaddle_height) && (ball_center_y < (window_bottom - 0.5*leftpaddle_height)))
    {
        this->ui->leftpaddle->setGeometry(
                    leftpaddle_left,                        //x coordinate
                    ball_center_y - 0.5*leftpaddle_height,  //y coordinate
                    leftpaddle_width,                       //width
                    leftpaddle_height);                     //height
    }
}

//PERFECT RIGHT PADDLE AI BEHAVIOUR
void MainWindow::AI_perfect_rightpaddle()
{
    //window variables (current top, current bottom, current left, current right)
    const int window_top = 0;
    const int window_bottom = this->geometry().height();    //not bottom!! (not sure why)
    const int window_right = this->geometry().width();      //not right!! (not sure why)

    //ball variables
    const int ball_top = this->ui->ball->geometry().top();
    const int ball_height = this->ui->ball->geometry().height();
    const int ball_center_y = ball_top + 0.5*ball_height;

    //right paddle variables
    const int rightpaddle_width = this->ui->rightpaddle->geometry().width();
    const int rightpaddle_height = this->ui->rightpaddle->geometry().height();


    //if not at edge of window, move right paddle with ball
    if ((ball_center_y > window_top + 0.5*rightpaddle_height) && (ball_center_y < (window_bottom - 0.5*rightpaddle_height)))
    {
        this->ui->rightpaddle->setGeometry(
                    window_right -70,                       //x coordinate
                    ball_center_y - 0.5*rightpaddle_height, //y coordinate
                    rightpaddle_width,                      //width
                    rightpaddle_height);                    //height
    }
}

//AFTER A POINT IS SCORED, WAIT A BIT AND RESTART STANDARD BALL BEHAVIOUR
void MainWindow::reinitialise()
{
    //window variables (current top, current bottom, current left, current right)
    const int window_center_x = (this->width()/2);
    const int window_center_y = (this->height()/2);

    //ball variables
    const int ball_width = this->ui->ball->geometry().width();
    const int ball_height = this->ui->ball->geometry().height();

    //wait a bit (not sure how yet)
    this->ui->ball->setGeometry(window_center_x, window_center_y, ball_width, ball_height);
    this->standardball();       //restart standard ball behaviour
}

//THIS HAPPENS WHEN THE BUTTON IS PRESSED
void MainWindow::on_pushButton_clicked()
{
    if (leftpaddle_up == true)
    {
        leftpaddle_up = false;
    }
    else
    {
        leftpaddle_up = true;
    }
}
