#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "credits.h"

#define PUSHBUTTON_NUMBER           90
#define RANGE_NUMBER_TO_GENERATE    90

bool colored[PUSHBUTTON_NUMBER];;
QPushButton* pushBtn[PUSHBUTTON_NUMBER];
uint8_t extractedNums[PUSHBUTTON_NUMBER];
uint8_t extrIdx;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QString str;

    ui->setupUi(this);

    fillPbArray();
    connectSlots();

    // Init variables and array
    extrIdx = 0;

    for (int i = 0; i < PUSHBUTTON_NUMBER; i++)
        extractedNums[i] = 0;

    // Writing numbers on each pushbutton
    for (int i = 0; i < PUSHBUTTON_NUMBER; i++)
    {
        str = QString::number(i + 1);
        pushBtn[i]->setText(str);
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
        colored[i] = false;

    pushBtn[0] = ui->pushBtn0;
    pushBtn[1] = ui->pushBtn1;
    pushBtn[2] = ui->pushBtn2;
    pushBtn[3] = ui->pushBtn3;
    pushBtn[4] = ui->pushBtn4;
    pushBtn[5] = ui->pushBtn5;
    pushBtn[6] = ui->pushBtn6;
    pushBtn[7] = ui->pushBtn7;
    pushBtn[8] = ui->pushBtn8;
    pushBtn[9] = ui->pushBtn9;
    pushBtn[10] = ui->pushBtn10;
    pushBtn[11] = ui->pushBtn11;
    pushBtn[12] = ui->pushBtn12;
    pushBtn[13] = ui->pushBtn13;
    pushBtn[14] = ui->pushBtn14;
    pushBtn[15] = ui->pushBtn15;
    pushBtn[16] = ui->pushBtn16;
    pushBtn[17] = ui->pushBtn17;
    pushBtn[18] = ui->pushBtn18;
    pushBtn[19] = ui->pushBtn19;
    pushBtn[20] = ui->pushBtn20;
    pushBtn[21] = ui->pushBtn21;
    pushBtn[22] = ui->pushBtn22;
    pushBtn[23] = ui->pushBtn23;
    pushBtn[24] = ui->pushBtn24;
    pushBtn[25] = ui->pushBtn25;
    pushBtn[26] = ui->pushBtn26;
    pushBtn[27] = ui->pushBtn27;
    pushBtn[28] = ui->pushBtn28;
    pushBtn[29] = ui->pushBtn29;
    pushBtn[30] = ui->pushBtn30;
    pushBtn[31] = ui->pushBtn31;
    pushBtn[32] = ui->pushBtn32;
    pushBtn[33] = ui->pushBtn33;
    pushBtn[34] = ui->pushBtn34;
    pushBtn[35] = ui->pushBtn35;
    pushBtn[36] = ui->pushBtn36;
    pushBtn[37] = ui->pushBtn37;
    pushBtn[38] = ui->pushBtn38;
    pushBtn[39] = ui->pushBtn39;
    pushBtn[40] = ui->pushBtn40;
    pushBtn[41] = ui->pushBtn41;
    pushBtn[42] = ui->pushBtn42;
    pushBtn[43] = ui->pushBtn43;
    pushBtn[44] = ui->pushBtn44;
    pushBtn[45] = ui->pushBtn45;
    pushBtn[46] = ui->pushBtn46;
    pushBtn[47] = ui->pushBtn47;
    pushBtn[48] = ui->pushBtn48;
    pushBtn[49] = ui->pushBtn49;
    pushBtn[50] = ui->pushBtn50;
    pushBtn[51] = ui->pushBtn51;
    pushBtn[52] = ui->pushBtn52;
    pushBtn[53] = ui->pushBtn53;
    pushBtn[54] = ui->pushBtn54;
    pushBtn[55] = ui->pushBtn55;
    pushBtn[56] = ui->pushBtn56;
    pushBtn[57] = ui->pushBtn57;
    pushBtn[58] = ui->pushBtn58;
    pushBtn[59] = ui->pushBtn59;
    pushBtn[60] = ui->pushBtn60;
    pushBtn[61] = ui->pushBtn61;
    pushBtn[62] = ui->pushBtn62;
    pushBtn[63] = ui->pushBtn63;
    pushBtn[64] = ui->pushBtn64;
    pushBtn[65] = ui->pushBtn65;
    pushBtn[66] = ui->pushBtn66;
    pushBtn[67] = ui->pushBtn67;
    pushBtn[68] = ui->pushBtn68;
    pushBtn[69] = ui->pushBtn69;
    pushBtn[70] = ui->pushBtn70;
    pushBtn[71] = ui->pushBtn71;
    pushBtn[72] = ui->pushBtn72;
    pushBtn[73] = ui->pushBtn73;
    pushBtn[74] = ui->pushBtn74;
    pushBtn[75] = ui->pushBtn75;
    pushBtn[76] = ui->pushBtn76;
    pushBtn[77] = ui->pushBtn77;
    pushBtn[78] = ui->pushBtn78;
    pushBtn[79] = ui->pushBtn79;
    pushBtn[80] = ui->pushBtn80;
    pushBtn[81] = ui->pushBtn81;
    pushBtn[82] = ui->pushBtn82;
    pushBtn[83] = ui->pushBtn83;
    pushBtn[84] = ui->pushBtn84;
    pushBtn[85] = ui->pushBtn85;
    pushBtn[86] = ui->pushBtn86;
    pushBtn[87] = ui->pushBtn87;
    pushBtn[88] = ui->pushBtn88;
    pushBtn[89] = ui->pushBtn89;
}

void MainWindow::on_creditsBtn_released()
{
    Credits creditsPopUp;
    creditsPopUp.setModal(true);
    creditsPopUp.exec();
}

void MainWindow::on_drawBtn_released()
{
    uint8_t n;
    clock_t t;
    bool alreadyPresent = false;

    t = clock();
    srand(t);

    do
    {
        alreadyPresent = false;
        // Generating a non-zero random number
        do
        {
            n = rand() % (RANGE_NUMBER_TO_GENERATE + 1);
        } while (n == 0);

        for (int i = 0; i < extrIdx; i++)
        {
            if (extractedNums[i] == n)
            {
                alreadyPresent = true;
                break;
            }
        }
    } while ((alreadyPresent) && (extrIdx < PUSHBUTTON_NUMBER));

    if (extrIdx == PUSHBUTTON_NUMBER)
    {
        alreadyPresent = true;
        n = 0;
    }

    if (!alreadyPresent)
    {
        extractedNums[extrIdx] = n;
        extrIdx++;
    }

    ui->numberTxt->setText(QString::number(n));
    ui->numberTxt->setFontPointSize(42);
    ui->numberTxt->setAlignment(Qt::AlignCenter);
}
