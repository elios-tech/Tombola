#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "credits.h"

#define PUSHBUTTON_NUMBER           81
#define RANGE_NUMBER_TO_GENERATE    90
#define NUMBER_PER_FOLDER           27
#define TOTAL_FOLDER_NUMBER         3
#define TOTAL_PUSHBUTTON_FOLDER     27
#define NUMBER_OF_ROWS              3
#define NUMBER_OF_COLS              9
#define NUMBER_OF_LABEL_TO_BLANK    4

bool colored[PUSHBUTTON_NUMBER];;
QPushButton* pushBtn[PUSHBUTTON_NUMBER];
bool pbClickable[PUSHBUTTON_NUMBER];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    uint8_t number;
    uint8_t numArray[NUMBER_PER_FOLDER] = {};
    bool alreadyPresent;
    uint8_t units, ten, twenty, thirty, fourty, fifty, sixty, seventy, eighty;
    uint8_t unitsArr[3], tenArr[3], twentyArr[3], thirtyArr[3], fourtyArr[3], fiftyArr[3], sixtyArr[3], seventyArr[3], eigthyArr[3];
    uint8_t unitsIdx, tenIdx, twnetyIdx, thirtyIdx, fourtyIdx, fiftyIdx, sixtyIdx, seventyIdx, eigthyIdx;
    clock_t t;
    QString str;

    ui->setupUi(this);

    fillPbArray();
    connectSlots();

    // Genrating random number for the three folder
    for (int k = 0; k < TOTAL_FOLDER_NUMBER; k++)
    {
        t = clock() / (3 * (k + 1));
        srand(t);
        units = 0;
        ten = 0;
        twenty = 0;
        thirty = 0;
        fourty = 0;
        fifty = 0;
        sixty = 0;
        seventy = 0;
        eighty = 0;
        for (int i = 0; i < NUMBER_PER_FOLDER;)
        {
            alreadyPresent = false;
            // Generating a non-zero random number
            do
            {
                number = rand() % (RANGE_NUMBER_TO_GENERATE + 1);
            } while (number == 0);

            // Checking if the generated number is already in the array
            for (int j = 0; j < i; j++)
            {
                if (number == numArray[j])
                {
                    alreadyPresent = true;
                    break;
                }
            }

            // Checking if, with the last generated number,
            // the number of tens, twenties, etc, are less than 3.
            if (!alreadyPresent)
            {
                if ((number < 10) && (units < 3)) units++;
                else if (((number >= 10) && (number < 20)) && ten < 3) ten++;
                else if (((number >= 20) && (number < 30)) && twenty < 3) twenty++;
                else if (((number >= 30) && (number < 40)) && thirty < 3) thirty++;
                else if (((number >= 40) && (number < 50)) && fourty < 3) fourty++;
                else if (((number >= 50) && (number < 60)) && fifty < 3) fifty++;
                else if (((number >= 60) && (number < 70)) && sixty < 3) sixty++;
                else if (((number >= 70) && (number < 80)) && seventy < 3) seventy++;
                else if (((number >= 80) && (number < 90)) && eighty < 3) eighty++;
                else if ((number == 90) && eighty < 1) eighty++;
                else alreadyPresent = true;
            }

            if (!alreadyPresent)
            {
                numArray[i] = number;
                i++;
            }
        }

        // Clearing auxiliary vectors and indexes
        for (int i = 0; i < NUMBER_OF_ROWS; i++)
        {
            unitsArr[i] = 0;
            tenArr[i] = 0;
            twentyArr[i] = 0;
            thirtyArr[i] = 0;
            fourtyArr[i] = 0;
            fiftyArr[i] = 0;
            sixtyArr[i] = 0;
            seventyArr[i] = 0;
            eigthyArr[i] = 0;
        }
        unitsIdx = 0;
        tenIdx = 0;
        twnetyIdx = 0;
        thirtyIdx = 0;
        fourtyIdx = 0;
        fiftyIdx = 0;
        sixtyIdx = 0;
        seventyIdx = 0;
        eigthyIdx = 0;

        // Filling up auxiliary arrays. Each array contains the generated numbers
        // with the same tens.
        for (int z = 0; z < NUMBER_PER_FOLDER; z++)
        {
            if ((numArray[z] / 10) == 0) unitsArr[unitsIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 1) tenArr[tenIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 2) twentyArr[twnetyIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 3) thirtyArr[thirtyIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 4) fourtyArr[fourtyIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 5) fiftyArr[fiftyIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 6) sixtyArr[sixtyIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 7) seventyArr[seventyIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 8) eigthyArr[eigthyIdx++] = numArray[z];
            else if ((numArray[z] / 10) == 9) eigthyArr[eigthyIdx++] = numArray[z];
        }

        // Writing all numbers in the pushbutton labels
        for (int t = 0; t < NUMBER_OF_ROWS; t++)
        {
            str = (unitsArr[t] != 0) ? QString::number(unitsArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9)]->setText(str);

            str = (tenArr[t] != 0) ? QString::number(tenArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9) + 1]->setText(str);

            str = (twentyArr[t] != 0) ? QString::number(twentyArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9) + 2]->setText(str);

            str = (thirtyArr[t] != 0) ? QString::number(thirtyArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9) + 3]->setText(str);

            str = (fourtyArr[t] != 0) ? QString::number(fourtyArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9) + 4]->setText(str);

            str = (fiftyArr[t] != 0) ? QString::number(fiftyArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9) + 5]->setText(str);

            str = (sixtyArr[t] != 0) ? QString::number(sixtyArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9) + 6]->setText(str);

            str = (seventyArr[t] != 0) ? QString::number(seventyArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9) + 7]->setText(str);

            str = (eigthyArr[t] != 0) ? QString::number(eigthyArr[t]) : " ";
            pushBtn[(k * 27) + (t * 9) + 8]->setText(str);
        }

        // Clearing array
        for (int i = 0; i < NUMBER_PER_FOLDER; i++)
            numArray[i] = 0;

        for (int z = 0; z < NUMBER_OF_ROWS; z++)
        {
            for (int i = 0; i < 4;)
            {
                alreadyPresent = false;
                // Generating a non-zero random number
                do
                {
                    number = rand() % 9;
                } while (number == 0);

                // Checking if the generated number is already in the array
                for (int j = 0; j < i; j++)
                {
                    if (number == numArray[j])
                    {
                        alreadyPresent = true;
                        break;
                    }
                }

                if (!alreadyPresent)
                {
                    numArray[i] = number;
                    i++;
                }
            }

            // Randomly removing 4 numbers on each row
            str = " ";
            for (int i = 0; i < NUMBER_OF_LABEL_TO_BLANK; i++)
            {
                pbClickable[(k * 27) + (z * 9) + numArray[i]] = false;
                pushBtn[(k * 27) + (z * 9) + numArray[i]]->setText(str);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintButton(void)
{
    int i;
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());

    for (i = 0; i < PUSHBUTTON_NUMBER; i++)
    {
        if (pButton == pushBtn[i])
            break;
    }

    if (pbClickable[i])
    {
        if (colored[i] == false)
        {
            pushBtn[i]->setStyleSheet("background-image: url(:/icons/pushbtnPressed_icon.png);\nbackground-color: rgb(0, 0, 0);");
            colored[i] = true;
        }
        else
        {
            pushBtn[i]->setStyleSheet("background-image: url(:/icons/pushbtn_icon.png);\nbackground-color: rgb(0, 0, 0);");
            colored[i] = false;
        }
    }
}

void MainWindow::connectSlots(void)
{
    for (int i = 0; i < PUSHBUTTON_NUMBER; i++)
    {
        connect(pushBtn[i], SIGNAL (released()), this, SLOT(paintButton()));
    }
}

void MainWindow::fillPbArray(void)
{
    for (int i = 0; i < PUSHBUTTON_NUMBER; i++)
        pbClickable[i] = true;

    for (int i = 0; i < PUSHBUTTON_NUMBER; i++)
        colored[i] = false;

    pushBtn[0] = ui->pushBtn_0;
    pushBtn[1] = ui->pushBtn_1;
    pushBtn[2] = ui->pushBtn_2;
    pushBtn[3] = ui->pushBtn_3;
    pushBtn[4] = ui->pushBtn_4;
    pushBtn[5] = ui->pushBtn_5;
    pushBtn[6] = ui->pushBtn_6;
    pushBtn[7] = ui->pushBtn_7;
    pushBtn[8] = ui->pushBtn_8;
    pushBtn[9] = ui->pushBtn_9;
    pushBtn[10] = ui->pushBtn_10;
    pushBtn[11] = ui->pushBtn_11;
    pushBtn[12] = ui->pushBtn_12;
    pushBtn[13] = ui->pushBtn_13;
    pushBtn[14] = ui->pushBtn_14;
    pushBtn[15] = ui->pushBtn_15;
    pushBtn[16] = ui->pushBtn_16;
    pushBtn[17] = ui->pushBtn_17;
    pushBtn[18] = ui->pushBtn_18;
    pushBtn[19] = ui->pushBtn_19;
    pushBtn[20] = ui->pushBtn_20;
    pushBtn[21] = ui->pushBtn_21;
    pushBtn[22] = ui->pushBtn_22;
    pushBtn[23] = ui->pushBtn_23;
    pushBtn[24] = ui->pushBtn_24;
    pushBtn[25] = ui->pushBtn_25;
    pushBtn[26] = ui->pushBtn_26;
    pushBtn[27] = ui->pushBtn_27;
    pushBtn[28] = ui->pushBtn_28;
    pushBtn[29] = ui->pushBtn_29;
    pushBtn[30] = ui->pushBtn_30;
    pushBtn[31] = ui->pushBtn_31;
    pushBtn[32] = ui->pushBtn_32;
    pushBtn[33] = ui->pushBtn_33;
    pushBtn[34] = ui->pushBtn_34;
    pushBtn[35] = ui->pushBtn_35;
    pushBtn[36] = ui->pushBtn_36;
    pushBtn[37] = ui->pushBtn_37;
    pushBtn[38] = ui->pushBtn_38;
    pushBtn[39] = ui->pushBtn_39;
    pushBtn[40] = ui->pushBtn_40;
    pushBtn[41] = ui->pushBtn_41;
    pushBtn[42] = ui->pushBtn_42;
    pushBtn[43] = ui->pushBtn_43;
    pushBtn[44] = ui->pushBtn_44;
    pushBtn[45] = ui->pushBtn_45;
    pushBtn[46] = ui->pushBtn_46;
    pushBtn[47] = ui->pushBtn_47;
    pushBtn[48] = ui->pushBtn_48;
    pushBtn[49] = ui->pushBtn_49;
    pushBtn[50] = ui->pushBtn_50;
    pushBtn[51] = ui->pushBtn_51;
    pushBtn[52] = ui->pushBtn_52;
    pushBtn[53] = ui->pushBtn_53;
    pushBtn[54] = ui->pushBtn_54;
    pushBtn[55] = ui->pushBtn_55;
    pushBtn[56] = ui->pushBtn_56;
    pushBtn[57] = ui->pushBtn_57;
    pushBtn[58] = ui->pushBtn_58;
    pushBtn[59] = ui->pushBtn_59;
    pushBtn[60] = ui->pushBtn_60;
    pushBtn[61] = ui->pushBtn_61;
    pushBtn[62] = ui->pushBtn_62;
    pushBtn[63] = ui->pushBtn_63;
    pushBtn[64] = ui->pushBtn_64;
    pushBtn[65] = ui->pushBtn_65;
    pushBtn[66] = ui->pushBtn_66;
    pushBtn[67] = ui->pushBtn_67;
    pushBtn[68] = ui->pushBtn_68;
    pushBtn[69] = ui->pushBtn_69;
    pushBtn[70] = ui->pushBtn_70;
    pushBtn[71] = ui->pushBtn_71;
    pushBtn[72] = ui->pushBtn_72;
    pushBtn[73] = ui->pushBtn_73;
    pushBtn[74] = ui->pushBtn_74;
    pushBtn[75] = ui->pushBtn_75;
    pushBtn[76] = ui->pushBtn_76;
    pushBtn[77] = ui->pushBtn_77;
    pushBtn[78] = ui->pushBtn_78;
    pushBtn[79] = ui->pushBtn_79;
    pushBtn[80] = ui->pushBtn_80;
}

void MainWindow::on_creditsBtn_released()
{
    Credits creditsPopUp;
    creditsPopUp.setModal(true);
    creditsPopUp.exec();
}
