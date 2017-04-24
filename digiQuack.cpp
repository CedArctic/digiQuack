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

    int asciinum;//Case for A and a

    if(key.size() == 1){
        asciinum = (int)key[0];         //If the string length is 1, use a switch statement to improve speed. In order to do that we need to extract the character number in ascii with this line of code.

        switch(asciinum){

            case 65:
            case 97:
                key = "KEY_A";
                return key;
            case 66:
            case 98:
                key = "KEY_B";
                return key;
            case 67:
            case 99:
                key = "KEY_C";
                return key;
            case 68:
            case 100:
                key = "KEY_D";
                return key;
            case 69:
            case 101:
                key = "KEY_E";
                return key;
            case 70:
            case 102:
                key = "KEY_F";
                return key;
            case 71:
            case 103:
                key = "KEY_G";
                return key;
            case 72:
            case 104:
                key = "KEY_H";
                return key;
            case 73:
            case 105:
                key = "KEY_I";
                return key;
            case 74:
            case 106:
                key = "KEY_J";
                return key;
            case 75:
            case 107:
                key = "KEY_K";
                return key;
            case 76:
            case 108:
                key = "KEY_L";
                return key;
            case 77:
            case 109:
                key = "KEY_M";
                return key;
            case 78:
            case 110:
                key = "KEY_N";
                return key;
            case 79:
            case 111:
                key = "KEY_O";
                return key;
            case 80:
            case 112:
                key = "KEY_P";
                return key;
            case 81:
            case 113:
                key = "KEY_Q";
                return key;
            case 82:
            case 114:
                key = "KEY_R";
                return key;
            case 83:
            case 115:
                key = "KEY_S";
                return key;
            case 84:
            case 116:
                key = "KEY_T";
                return key;
            case 85:
            case 117:
                key = "KEY_U";
                return key;
            case 86:
            case 118:
                key = "KEY_V";
                return key;
            case 87:
            case 119:
                key = "KEY_W";
                return key;
            case 88:
            case 120:
                key = "KEY_X";
                return key;
            case 89:
            case 121:
                key = "KEY_Y";
                return key;
            case 90:
            case 122:
                key = "KEY_Z";
                return key;
            case 48:
                key = "KEY_0";
                return key;
            case 49:
                key = "KEY_1";
                return key;
            case 50:
                key = "KEY_2";
                return key;
            case 51:
                key = "KEY_3";
                return key;
            case 52:
                key = "KEY_4";
                return key;
            case 53:
                key = "KEY_5";
                return key;
            case 54:
                key = "KEY_6";
                return key;
            case 55:
                key = "KEY_7";
                return key;
            case 56:
                key = "KEY_8";
                return key;
            case 57:
                key = "KEY_9";
                return key;
            default:
                cout << "There was a problem in converting the ascii character:" << key << endl;        //In case the character doesn't exist in the switch
        }
    }


    if(key=="ENTER"){
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
            if(!command.empty() && command != key){         //If command is equal to key it means that the command is a one word line e.g ENTER so command.erase until a ' ' would have no effect.
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
        fileout << "for(;;){ /*empty*/ }";
    }

    //Close converted script txt fstream
    fileout.close();
    return 0;
}
