const path = require('path');
const fs = require('fs');
let project = new Project('engine');
 
project.addProvider = function(proj, isRoot=false){
    const sdl2 = true;//process.argv.indexOf("--sdl2") >= 0;
    if(sdl2){
        
        if(!isRoot){
            proj.addDefine("USE_SDL");
            proj.addDefine("DEBUG_MODE");
            proj.addIncludeDir(path.resolve("./SDL/include"));
        }
        proj.addLib("../SDL/lib/SDL2");
        proj.addLib("../SDL/lib/SDL2main");
        proj.addLib("../SDL/lib/SDL2_image");
        proj.addLib("../SDL/lib/SDL2_mixer");
        proj.addLib("../SDL/lib/SDL2_ttf");
        if (!fs.existsSync("./Deployment/SDL2.dll"))
        {
            fs.copyFileSync("./SDL/lib/SDL2.dll", "./Deployment/SDL2.dll")
            fs.copyFileSync("./SDL/lib/SDL2_image.dll", "./Deployment/SDL2_image.dll")
            fs.copyFileSync("./SDL/lib/SDL2_mixer.dll", "./Deployment/SDL2_mixer.dll")
            fs.copyFileSync("./SDL/lib/SDL2_ttf.dll", "./Deployment/SDL2_ttf.dll")
        }
    }
};
project.kore = false;


project.addDefine("KINC_STATIC_COMPILE");
project.isStaticLib = true;

project.addIncludeDir(path.resolve("./TheEngine/includes"));
project.addFiles('sources/**','includes/**');
project.addLib("C:/Program Files (x86)/Visual Leak Detector/lib/Win64/vld");
project.addIncludeDir("C:/Program Files (x86)/Visual Leak Detector/include");

project.addProvider(project,false);

resolve(project);