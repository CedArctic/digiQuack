/*	 

 duck2python converts DuckyScript scripts for the USB Rubber Ducky by hak5 to python scripts that function the same way
thus offering a convenient way of testing a script without requiring to load it on a Rubber Ducky each time.

*/

/*

# Print Ascii Art:
print("     _            _          ____              _   _                 ")
print("  __| |_   _  ___| | ___   _|___ \\ _ __  _   _| |_| |__   ___  _ __  ")
print(" / _` | | | |/ __| |/ / | | | __) | '_ \\| | | | __| '_ \\ / _ \\| '_ \\ ")
print("| (_| | |_| | (__|   <| |_| |/ __/| |_) | |_| | |_| | | | (_) | | | |")
print(" \\__,_|\\__,_|\\___|_|\\_\\\\__, |_____| .__/ \\__, |\\__|_| |_|\\___/|_| |_|")
print("                       |___/      |_|    |___/ \tby CedArctic                 ")
print("\n\n")

*/

function convert(){
	// Declare and load Ducky Script and Digispark output:
	var duckyScript = document.getElementById('inputBox').value;
	var digisparkScript = "";

	// Write module imports to output file:
	digisparkScript += "// Converted using digiQuack by CedArctic (https://github.com/CedArctic/digiQuack) \n\n";
	digisparkScript +="#include \"DigiKeyboard.h\"\n\n";
	digisparkScript += "void setup() {}\n\n";
	digisparkScript += "void loop() {\n";
	digisparkScript += "\tDigiKeyboard.sendKeyStroke(0);\n";

	// Convert the Ducky Script lines to a list and stip whitespaces:
	duckyScript = duckyScript.split(/\r\n|\r|\n/g);
	/* Ducky Statements fall into one of the following 6 categories:
	1. Default Delay	2.Comment	3.Delay 	4.String	5.Repeat	6.Command */

	// Check if there is a default delay:
	var defaultDelay = 0;
	if (duckyScript[0].slice(0,7) == "DEFAULT"){
		defaultDelay = parseInt(duckyScript[0].slice(7));
		duckyScript.shift();
	}

	// Variables:
	var previousStatement = "";	
	var keys = [];
		
	// Dictionary containing Duckyscript and their corresponding Digispark keys
	var ducky2digi = {"WINDOWS":"0, MOD_GUI_LEFT", "GUI":"0, MOD_GUI_LEFT", "APP":"101", "MENU":"101",
	"SHIFT":"MOD_SHIFT_LEFT", "ALT":"MOD_ALT_LEFT", "CONTROL":"MOD_CONTROL_LEFT", "CTRL":"MOD_CONTROL_LEFT",
	"DOWNARROW":"81", "DOWN":"81", "LEFTARROW":"80", "LEFT":"80", "RIGHTARROW":"79", "RIGHT":"79", "UPARROW":"82",
	"UP":"82", "BREAK":"72", "PAUSE":"72", "CAPSLOCK":"57", "DELETE":"42", "END":"42", "ESC":"41", "ESCAPE":"41",
	"HOME":"74", "NUMLOCK":"83", "PAGEUP":"75", "PAGEDOWN":"78", "PRINTSCREEN":"70", "SCROLLLOCK":"71", "SPACE":"44", 
	"TAB":"43", "ENTER":"KEY_ENTER", "F1":"KEY_F1", "F2":"KEY_F2", "F3":"KEY_F3", "F4":"KEY_F4", "F5":"KEY_F5",
	"F6":"KEY_F6", "F7":"KEY_F7", "F8":"KEY_F8", "F9":"KEY_F9", "F10":"KEY_F10", "F11":"KEY_F11", "F12":"KEY_F12",
	"a":"KEY_A", "b":"KEY_B", "c":"KEY_C", "d":"KEY_D", "e":"KEY_E", "f":"KEY_F", "g":"KEY_G", "h":"KEY_H",
	"i":"KEY_I", "j":"KEY_J", "k":"KEY_K", "l":"KEY_L", "m":"KEY_M", "n":"KEY_N", "o":"KEY_O", "p":"KEY_P",
	"q":"KEY_Q", "r":"KEY_R", "s":"KEY_S", "t":"KEY_T", "u":"KEY_U", "v":"KEY_V", "w":"KEY_W", "x":"KEY_X",
	"y":"KEY_Y", "z":"KEY_Z", "A":"KEY_A", "B":"KEY_B", "C":"KEY_C", "D":"KEY_D", "E":"KEY_E", "F":"KEY_F", 
	"G":"KEY_G", "H":"KEY_H", "I":"KEY_I", "J":"KEY_J", "K":"KEY_K", "L":"KEY_L", "M":"KEY_M", "N":"KEY_N",
	"O":"KEY_O", "P":"KEY_P", "Q":"KEY_Q", "R":"KEY_R", "S":"KEY_S", "T":"KEY_T", "U":"KEY_U", "V":"KEY_V",
	"W":"KEY_W", "X":"KEY_X", "Y":"KEY_Y", "Z":"KEY_Z", "1":"KEY_1", "2":"KEY_2", "3":"KEY_3", "4":"KEY_4", 
	"5":"KEY_5", "6":"KEY_6", "7":"KEY_7", "8":"KEY_8", "9":"KEY_9", "0":"KEY_0", "!":"30", "\"":"49", "#":"32", 
	"$":"33", "%":"34", "&":"36", "\'":"52", "(":"38", ")":"39", "*":"37", "+":"46", ",":"54", "-":"45", ".":"55",
	"/":"56", ":":"51", ";":"51", "<":"54", "=":"46", ">":"55", "?":"56", "@":"31", "[":"47", "]":"48", "^":"35",
	"_":"45", "`":"53", "{":"47", "|":"49", "}":"48", "~":"53"};

	// Process each line from the ducky script:
	for (line = 0; line < duckyScript.length; line++){

		// Check if the statement is a comment, delay, string, repeat or key combination
		if(duckyScript[line].slice(0,3) == "REM"){
			previousStatement = duckyScript[line].replace("REM","\t//");
		}else if (duckyScript[line].slice(0,5) == "DELAY"){
			previousStatement = "\tDigiKeyboard.delay(" + parseInt(duckyScript[line].slice(6)) + ");";
		}else if (duckyScript[line].slice(0,6) == "STRING") {
			previousStatement = "\tDigiKeyboard.print(\"" + duckyScript[line].slice(7).replaceAll("\\", "\\\\").replaceAll("\"", "\\\"") + "\");";
		}else if (duckyScript[line].slice(0,6) == "REPEAT"){
			var repetitions = parseInt(duckyScript[line].slice(7)) - 1;
			for (i = 0; i < repetitions; i++){
				digisparkScript += previousStatement;
				digisparkScript += "\n";

				// Write Default Delay between the commands if it exists:
				if (defaultDelay != 0){
					digisparkScript += "\tDigiKeyboard.delay(" + defaultDelay + ");\n";
				}
			}
		}else{
			// Write beginning of command:
			previousStatement = "\tDigiKeyboard.sendKeyStroke(";
			// Split statement into keys
			keys = duckyScript[line].split(" ");
			// Go through the keys matching them through the dictionary to Digispark keys
			for (j = 0; j < keys.length; j++){
				if (keys[j] in ducky2digi){
					previousStatement += ducky2digi[keys[j]] + ",";
				}else{
					// If it is not in the dictionary
					previousStatement += "UNDEFINED_KEY" + ",";
				}
			}
			// Remove last comma and add a parenthesis
			previousStatement = previousStatement.slice(0, previousStatement.length - 1) + ");";
		}

		// Write command to output file and add a new line \n :
		digisparkScript += previousStatement;
		digisparkScript += "\n";

		// Write Default Delay if it exists:
		if (defaultDelay != 0){
			digisparkScript += "\tDigiKeyboard.delay(" + defaultDelay + ");\n";
		}
	}
	digisparkScript += "}";
	// Write Output
	document.getElementById('outputBox').value = digisparkScript;
}