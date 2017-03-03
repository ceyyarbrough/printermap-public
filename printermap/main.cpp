
/*
Author: Christopher Yarbrough
Date: 01 March 2017
Version: 1.2
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

string serverName;
string printerName;
string printerAddress;
int linkName;

//function to store and return printer network address
string getPrinterAddress(){
    cout<<"Enter Server Name (EX: ******)"<<endl;
    cin>> serverName;
    cout<<"Enter Printer Name (EX: *******)"<<endl;
    cin>> printerName;
    //error null input
    if(serverName == "" || printerName == ""){
        cout<<"Error. Re-open program and try again."<<endl;
        return 0;//end program
    } else {
        printerAddress = ;//network address here
        return printerAddress;
    }
}


int main(){
    //returns function and prints to console
    printf("***CAUTION***\n");
    printf("This program is NOT designed for local printers (i.e. USB)\n");
    printf("It is designed for network printers ONLY\n");
    printf(" \n");
    printf(" \n");
    printf("NOTE: \n");
    printf("The first printer added will automatically\n");
    printf("be the default printer for the current user.\n");
    printf("\n");
    printf("\n");
    printf("If a new printer is new default, contact\n");
    printf("your support staff to change this setting.\n");
    printf("--------------\n");
    printf("Please Follow Instructions Carefully:\n");
    printf(" \n");
    getPrinterAddress();

    //stores system commands to .cmd
    ofstream printerLink;
    printerLink.open( "addPrinter.cmd");
    printerLink << "rundll32 printui.dll,PrintUIEntry /in /n" + printerAddress;//printer command
    printerLink.close();
    //runs .cmd
    system("addPrinter.cmd");

    return 0;

}

