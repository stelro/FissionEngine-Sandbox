//
// Created by stel on 6/4/2017.
//

#ifndef PROJECT_DEBUGCONSOLE_HPP
#define PROJECT_DEBUGCONSOLE_HPP

//Engine External
#include "External/imgui/imgui.h"


#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))
#define IM_MAX(_A,_B)       (((_A) >= (_B)) ? (_A) : (_B))

namespace Fiene {

    class DebugConsole {
    public:
                                    DebugConsole();
                                    ~DebugConsole();

        void                        ClearLog();
        void                        AddLog(const char *fmt, ...) IM_PRINTFARGS(2);
        void                        Draw(const char *title, bool *p_open);
        void                        ExecCommand(const char *command_line);

        // In C++11 you are better off using lambdas for this sort of forwarding callbacks
        static int                  TextEditCallbackStub(ImGuiTextEditCallbackData *data);

        // Portable helpers
        static int                  Stricmp(const char *str1, const char *str2);
        static int                  Strnicmp(const char *str1, const char *str2, int n);
        static char*                Strdup(const char *str);
        int                         TextEditCallback(ImGuiTextEditCallbackData *data);

    private:
        char                        InputBuf[256];
        ImVector<char *>            Items;
        bool                        ScrollToBottom;
        ImVector<char *>            History;
        int                         HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
        ImVector<const char *>      Commands;
    };

}
#endif //PROJECT_DEBUGCONSOLE_HPP
