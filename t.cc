#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct T_ShellInfo
{
    string cmd;
    void (* DealFunc)(const vector<string> &vectStr);
    string desc;
};
class CShell
{
public:
    CShell();
    ~CShell();
    void RecvCmd();
private:   
    enum{SHELL_INFO_NUM_MAX=10};
    void GetCmd(const char *cmdStr, vector<string> &vectStr);
    void Deal(const vector<string> &vectStr);
    
    static void CmdHelp(const vector<string> &vectStr);
    static void CmdLed(const vector<string> &vectStr);
    static void CmdTask(const vector<string> &vectStr);
    static void CmdDisk(const vector<string> &vectStr);
    static void CmdTime(const vector<string> &vectStr);
    static void CmdReboot(const vector<string> &vectStr);
   
    CShell *_self;
    const static T_ShellInfo _shellInfo[SHELL_INFO_NUM_MAX]; 
};
const T_ShellInfo CShell::_shellInfo[SHELL_INFO_NUM_MAX]=
{
    {"?",       CmdHelp,    "show all cmd"},
    {"help",    CmdHelp,    "show all cmd"},
    {"time",    CmdTime,    "show sys time"},
    {"task",    CmdTask,    "show all task info"},
    {"disk",    CmdDisk,    "disk cmd [info ls cat rm format]"},
    {"led",     CmdLed,     "set led [normal charge alarm]"},
    {"reboot",  CmdReboot,  "reboot sys"},
    
    {"",NULL,""}

};

void CShell::Deal(const vector<string> &vectStr)
{
    for (unsigned char i = 0; i< SHELL_INFO_NUM_MAX; i++)
    {
        if (_shellInfo[i].cmd.length() == 0)
        {
            break;
        }
        if (_shellInfo[i].cmd == vectStr[0])
        {
            _shellInfo[i].DealFunc(vectStr);
            return;
        }
    }
    printf("cmd \"%s\" err!\r\n", vectStr[0].c_str());
}

void CShell::CmdTask(const vector<string> &vectStr)
{

}
