#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function to count the lines of the script to be converted
int linecounter(string dir){

	int counter = 0;

    string line;

    //Create new file stream to file to be converted
    ifstream file(dir);

    while (getline(file, line)){
        counter++;}

    return counter;
}

//Accepts a string and returns the value of the key(s) in digispark language
//Some of the keys are encoded using their usage IDs. Refer to http://www.usb.org/developers/hidpage/Hut1_12v2.pdf  (Page 53-59)
string stringprocessor(string key){

    if((key == "A") || (key == "a")){
        key = "KEY_A";
        return key;
    }

    else if((key == "B") || (key == "b")){
        key = "KEY_B";
        return key;
    }

    else if((key == "C") || (key == "c")){
        key = "KEY_C";
        return key;
    }

    else if((key == "D") || (key == "d")){
        key = "KEY_D";
        return key;
    }

    else if((key == "E") || (key == "e")){
        key = "KEY_E";
        return key;
    }

    else if((key == "F") || (key == "f")){
        key = "KEY_F";
        return key;
    }

    else if((key == "G") || (key == "g")){
        key = "KEY_G";
        return key;
    }

    else if((key == "H") || (key == "h")){
        key = "KEY_H";
        return key;
    }

    else if((key == "I") || (key == "i")){
        key = "KEY_I";
        return key;
    }

    else if((key == "J") || (key == "j")){
        key = "KEY_J";
        return key;
    }

    else if((key == "K") || (key == "k")){
        key = "KEY_K";
        return key;
    }

    else if((key == "L") || (key == "l")){
        key = "KEY_L";
        return key;
    }

    else if((key == "M") || (key == "m")){
        key = "KEY_M";
        return key;
    }

    else if((key == "N") || (key == "n")){
        key = "KEY_N";
        return key;
    }

    else if((key == "O") || (key == "o")){
        key = "KEY_O";
        return key;
    }

    else if((key == "P") || (key == "p")){
        key = "KEY_P";
        return key;
    }

    else if((key == "Q") || (key == "q")){
        key = "KEY_Q";
        return key;
    }

    else if((key == "R") || (key == "r")){
        key = "KEY_R";
        return key;
    }

    else if((key == "S") || (key == "s")){
        key = "KEY_S";
        return key;
    }

    else if((key == "T") || (key == "t")){
        key = "KEY_T";
        return key;
    }

    else if((key == "U") || (key == "u")){
        key = "KEY_U";
        return key;
    }

    else if((key == "V") || (key == "v")){
        key = "KEY_V";
        return key;
    }

    else if((key == "W") || (key == "w")){
        key = "KEY_W";
        return key;
    }

    else if((key == "X") || (key == "x")){
        key = "KEY_X";
        return key;
    }

    else if((key == "Y") || (key == "y")){
        key = "KEY_Y";
        return key;
    }

    else if((key == "Z") || (key == "z")){
        key = "KEY_Z";
        return key;
    }

    else if(key=="1"){
        key = "KEY_1";
        return key;
    }

    else if(key=="2"){
        key = "KEY_2";
        return key;
    }

    else if(key=="3"){
        key = "KEY_3";
        return key;
    }

    else if(key=="4"){
        key = "KEY_4";
        return key;
    }

    else if(key=="5"){
        key = "KEY_5";
        return key;
    }

    else if(key=="6"){
        key = "KEY_6";
        return key;
    }

    else if(key=="7"){
        key = "KEY_7";
        return key;
    }

    else if(key=="8"){
        key = "KEY_8";
        return key;
    }

    else if(key=="9"){
        key = "KEY_9";
        return key;
    }

    else if(key=="0"){
        key = "KEY_0";
        return key;
    }

    else if(key=="ENTER"){
        key = "KEY_ENTER";
        return key;
    }

    else if(key=="F1"){
        key = "KEY_F1";
        return key;
    }

    else if(key=="F2"){
        key = "KEY_F2";
        return key;
    }

    else if(key=="F3"){
        key = "KEY_F3";
        return key;
    }

    else if(key=="F4"){
        key = "KEY_F4";
        return key;
    }

    else if(key=="F5"){
        key = "KEY_F5";
        return key;
    }

    else if(key=="F6"){
        key = "KEY_F6";
        return key;
    }

    else if(key=="F7"){
        key = "KEY_F7";
        return key;
    }

    else if(key=="F8"){
        key = "KEY_F8";
        return key;
    }

    else if(key=="F9"){
        key = "KEY_F9";
        return key;
    }

    else if(key=="F10"){
        key = "KEY_F10";
        return key;
    }

    else if(key=="F11"){
        key = "KEY_F11";
        return key;
    }

    else if(key=="F12"){
        key = "KEY_F12";
        return key;
    }

    else if((key=="GUI") || (key=="WINDOWS")){
        key = "0, MOD_GUI_LEFT"; //Doesn't work without the 0, for some reason
        return key;
    }

    else if((key=="APP") || (key=="MENU")){
        key = "101";
        return key;
    }

    else if(key=="SHIFT"){
        key = "MOD_SHIFT_LEFT";
        return key;
    }

    else if(key=="ALT"){
        key = "MOD_ALT_LEFT";
        return key;
    }

    else if((key=="CONTROL") || (key=="CTRL")){
        key = "MOD_CONTROL_LEFT";
        return key;
    }

    else if((key=="DOWNARROW") || (key=="DOWN")){
        key = "81";
        return key;
    }

    else if((key=="UPARROW") || (key=="UP")){
        key = "82";
        return key;
    }

    else if((key=="LEFTARROW") || (key=="LEFT")){
        key = "80";
        return key;
    }

    else if((key=="RIGHTARROW") || (key=="RIGHT")){
        key = "79";
        return key;
    }

    else if((key=="BREAK") || (key=="PAUSE")){
        key = "72";
        return key;
    }

    else if(key=="CAPSLOCK"){
        key = "57";
        return key;
    }

    else if((key=="ESC") || (key=="ESCAPE")){
        key = "41";
        return key;
    }

    else if(key=="DELETE"){
        key = "42";
        return key;
    }

    else if(key=="END"){
        key = "77";
        return key;
    }

    else if(key=="HOME"){
        key = "74";
        return key;
    }

    else if(key=="NUMLOCK"){
        key = "83";
        return key;
    }

    else if(key=="PAGEUP"){
        key = "75";
        return key;
    }

    else if(key=="PAGEDOWN"){
        key = "78";
        return key;
    }

    else if(key=="PRINTSCREEN"){
        key = "70";
        return key;
    }

    else if(key=="SCROLLLOCK"){
        key = "71";
        return key;
    }

    else if(key=="SPACE"){
        key = "44";
        return key;
    }

    else if(key=="TAB"){
        key = "43";
        return key;
    }
}

int main(){

    //Eye-candy
    cout<<"  _      _      _"<<endl;
    cout<<">(.)__ <(.)__ =(.)__"<<endl;
    cout<<" (___/  (___/  (___/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Welcome to digiQuack, the easy DuckyScript to Digispark payload converter!"<<endl;

    //Ask user to enter path to file to be converted
    string dir;
    cout<<"Enter the path of the file to be converted:"<<endl;
    cin>>dir;

    //Open input file stream
    ifstream filein(dir);

    //Check if file stream opened - if file exists and is a valid input
    if(!filein){
        cout<<"File not found or invalid input."<<endl;
        return -1;
    }

    //Check if the input file is empty
    if ( filein.peek() == std::ifstream::traits_type::eof() )
    {
        cout<<"File supplied is empty"<<endl;
        return -1;

    }

    //Create a counter as big as the number of lines in the input file
    int counter = linecounter(dir);

    //Open converted file fstream and create text file
    ofstream fileout;
    fileout.open ("converted.txt");

    //Create a string variable to store each individual ducky command/line to process in the for loop
    string command;

    //Create a trigger for the default delay command - if default delay command is encountered, inject converted script with delay lines
    int delay = 0;

    //Insert this line in the beginning of the converted script to make sure that (on older systems) the first keystroke after a delay isn't missed
    fileout << "DigiKeyboard.sendKeyStroke(0);\n";

    //Create temporary string variables to use for string manipulation in the following for-loop
    string tmpstring;
    string tmpstring2;
    string fincom; //Use this variable to keep track of the last converted command to use in the repeat function
    string key; //Variable to be used in the keystroke conversion if clause underneath
    int replays = 0; //Replays counter for the REPLAY feature if clause underneath

    //Open a for loop to process each line/command of the input script
    for(int i=0; i<counter; i++){

        //Set command string equal to current line
        getline(filein, command);

        //Check for DEFAULT_DELAY or DEFAULTDELAY, set the delay variable and re-examine for-loop (Note: writing the delay commands happens at the end of the for-loop).
        tmpstring = tmpstring.assign(command,0,13);
        if((tmpstring.compare("DEFAULTDELAY ")==0) || (tmpstring.compare("DEFAULT_DELAY")==0)){
            command.erase(0,13);
            delay = stoi(command);
            continue;
        }

        //Convert duckyscript comments to Arduino IDE comments: Extract 3 first characters, if == REM, replace them with //, write to output and re-examine for-loop - this helps avoid placing unnecessary delay commands
        tmpstring = tmpstring.assign(command,0,3);
        if(tmpstring.compare("REM") == 0){
            command.replace(0,4,"//");
            fileout << command << "\n";
            continue;
        }

        //Convert duckyscript STRING commands to digispark print commands (Note, used F to store large strings to flash since the digispark has few RAM)
        tmpstring = tmpstring.assign(command,0,6);
        if(tmpstring.compare("STRING") == 0){
            command.replace(0,7,"DigiKeyboard.print(F(\"");
            command += "\"));";
            fincom = command; //See use of fincom above
            fileout << command << "\n";
            command = ""; //Empty the string so it won't trigger the keystroke processor
        }

        //Convert DELAY command (Not DEFAULTDELAY)
        tmpstring = tmpstring.assign(command,0,5);
        if(tmpstring.compare("DELAY") == 0){
            command.erase(0,6);
            fincom = "DigiKeyboard.delay(" + command + ");";
            fileout << fincom << "\n";
            command = ""; //command variable is set to null to bypass keystroke processor but still access default delay
        }

        //REPLAY feature (Note: at the end, command variable is set to null to bypass keystroke processor but still access default delay)
        tmpstring = tmpstring.assign(command,0,5);
        if(tmpstring.compare("REPLAY") == 0){
            command.erase(0,6);
            replays = stoi(command);
            for(int j=0; j < replays; j++){
                fileout << fincom << "\n";
            }
            command = "";
        }

        //Convert keystroke commands by calling the string processor function
        if(!command.empty()){
            key = command.substr(0, command.find(' '));
            tmpstring = "DigiKeyboard.sendKeyStroke(" + stringprocessor(key);
            command.erase(0, command.find(' ')+1);
            if(!command.empty()){
                tmpstring = tmpstring + ",";
                tmpstring = tmpstring + stringprocessor(command);
            }
            tmpstring = tmpstring + ");";
            fincom = tmpstring;
            fileout << fincom << "\n";
        }

        //If default delay trigger is activated, inject output file with a delay command
        if(delay!=0){
            fileout << "DigiKeyboard.delay(" << delay << ");\n";
        }
    }

    //Ask if user wants to execute the script just once - Use the counter variable instead of initialising a new one since counter won't be used anymore.
    cout << "Script has been converted successfully. Do you want the DigiSpark to execute the script once or loop infinitely? Select 0 for infinity and 1 for a single execution." << endl;
    cout << "[0/1]:";
    cin >> counter;

    if(counter){
        fileout << "exit();";
    }

    //Close converted script txt fstream
    fileout.close();
    return 0;
}
