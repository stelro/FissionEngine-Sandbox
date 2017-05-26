//
// Created by stel on 25/5/2017.
//

#ifndef PROJECT_MAINWINDOW_HPP
#define PROJECT_MAINWINDOW_HPP

namespace Fiene {

    class Window;
    class FreeListAllocator;
    class PoolAllocator;
    class TexturesManager;

}

namespace Editor {

    class MapEditor;

    class MainWindow {
    public:
        MainWindow();
        ~MainWindow();

        void run();

    private:

        void init();
        void destroy();
        void showMenuBar();

        void createNewLevel();
    private:

        bool m_IsRunning;
        Fiene::Window* m_Window;
        MapEditor*      m_MapEditorWindow;

        void *m_PMemory;
        Fiene::FreeListAllocator*   m_FreeListAllocator;
        Fiene::PoolAllocator*       m_PoolAllocator;
        Fiene::TexturesManager*     m_TexturesManager;

        bool m_CreateNewLevel_Signal;

    };

}

#endif //PROJECT_MAINWINDOW_HPP
