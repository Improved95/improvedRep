#include "Messages.h"
using std::cout;
using std::endl;

void ShowMessages::showMessage(const string &message) const {
    cout << message << endl;
}

void ShowInfo::coutInstruction() {
    const string message =  "Describe in config.txt used converters and their parameters. Converters are applied sequentially.\n"
                      "You have 3 options of convert:\n"
                      "mute <t1> <t2>\t\t - Mute input1 from t1 to t2 seconds input1;\n"
                      "mix <t1> <t2> -i <2> <t3>\t - Mix input1 from t1 to t2 second with input2 starts from t3 second;\n"
                      "delay <t1> <Dry/Wet(int (0-100))> <FeedBack(int)> <Temp(int)> <Time Of delay(int)>\t - Creates an echo effect of the original sound from t1. Parameters: Degree of mixing;\n"
                      "Number of repetitions; Period of repetitions(ms); The time of one echo(ms).\n"
                      "\n\nconfig.txt example:\n"
                      "# Mute first 30s in input1\n"
                      "mute 0 30\n"
                      "\n# Mix input1 with input2, start from 10s"
                      "\nmix $2 10\n"
                      "\n# Mute third minute in mixed stream"
                      "\nmute 120 180";
    showMessage(message);
}
