--
-- Created by IntelliJ IDEA.
-- User: stel
-- Date: 22/6/2017
-- Time: 4:34 πμ
-- To change this template use File | Settings | File Templates.
--

textureManager = nil;
spriteBatch = nil;

function init()

   print("Initialization of draw_text script");

   textureManager = TexturesManager.getInstance();
   -- textureManager:load("Textures/mhouse.png");

   -- spriteBatch = SpriteBatch.new();
   -- spriteBatch:startUp();

end


