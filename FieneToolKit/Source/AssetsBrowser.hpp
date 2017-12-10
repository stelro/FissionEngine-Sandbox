//
// Created by stel on 28/5/2017.
//

#ifndef PROJECT_ASSETSBROWSER_HPP
#define PROJECT_ASSETSBROWSER_HPP

namespace Fiene {
    class TexturesManager;
}

namespace Editor {

    class AssetsBrowser {
    public:
        AssetsBrowser();
        ~AssetsBrowser();

        void create(Fiene::TexturesManager* texturesManager);
        void destroy();
        void render();

        void refreshTexturesArray();

    private:
        Fiene::TexturesManager*     m_TexturesManager;
        bool m_WindowIsOpen;

        int m_TexturesAssetsSizeCounter;

        char* m_AssetsNames[];
    };
}


#endif //PROJECT_ASSETSBROWSER_HPP
