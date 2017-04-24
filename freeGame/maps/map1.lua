--
-- Created by IntelliJ IDEA.
-- User: stel
-- Date: 4/3/2017
-- Time: 1:02 πμ
-- To change this template use File | Settings | File Templates.
--


 -- header
header = {
    name = "level_1",
    orientation = "orthogonal",
    map_width = 40,
    map_height = 40
}

tilesets =  {

    [1] = {
        name = "tileset1",
        path = "Textures/tmw_desert_spacing.png",
        width = 32,
        height = 32,
        spacing = 0,
        margin = 0
    }
}

layers = {

    [1] = {
        layer_type = "tileset",
        data_path = "maps/levels/level_1.map"
    }
}