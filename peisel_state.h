/*************************************************************************************************
 Copyright 2022 Jamar Phillip

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*************************************************************************************************/
#pragma once
#include "gui_ids.h"
#include "pen_engine/src/pen_engine.h"

#define CANVAS_TOP_MARGIN 20.0f

/*This is for having a selected vertical list open from the nav bar*/
struct OptionList {
    std::string name;
    pen::ui::Item* data;
} optionList;

/*For creating resizeable shapes*/
struct PeiselShape {
    unsigned int type;
    pen::Item* item;
    float scaleX = 1.0f;
    float scaleY = 1.0f;
};

/*For tile sprites*/
struct PeiselTileSprite {
    pen::Item* item;
    int tile;
};

class PeiselState {
    static PeiselState* instance;
public:
    const unsigned int SCR_WIDTH = 960;
    const unsigned int SCR_HEIGHT = 540;
    unsigned int tool = PEISEL_BRUSH;
    double mouseX = 0.0f;
    double mouseY = 0.0f;
    double* mouseXPtr = &mouseX;
    double* mouseYPtr = &mouseY;
    pen::ui::Item* navBar = nullptr;
    pen::ui::Item* currentColorBox = nullptr;
    pen::ui::Item* saveBox = nullptr;
    unsigned int appMode = PEISEL_DRAW;
    bool action = false;
    unsigned int appState = DRAW_BRUSHING;
    std::string outputFile = "";
    bool changes = false;
    
    /*----Draw Mode----*/
    pen::Vec4 currentColor = pen::Vec4(0.0f, 0.0f, 0.0f, 1.0f);
    bool penActive = false;
    std::vector<PeiselShape*> shapes;
    unsigned int currentShape = 0;
    PeiselShape* currentShapeData = nullptr;
    pen::Item* editBox = nullptr;
    bool updateCanvas = false;
    unsigned int brushSize = BRUSH_SMALL;
    unsigned char* freeDrawBuffer = nullptr;
    /*----Draw Mode----*/

    /*----Sprite Sheet Mode----*/
    bool spritesLoaded = false;
    bool spriteSelect = false;
    std::vector<pen::Item*> sprites;
    pen::ui::Item* spriteFileModal = nullptr;
    /*----Sprite Sheet Mode----*/

    /*----Tile Mode----*/
    char* tiles = nullptr;
    int tileSize = TILES_10;
    std::vector<std::string> selectableTileSprites;
    std::vector<PeiselTileSprite> tileSprites;
    std::vector<PeiselTileSprite> collisionBoxes;
    std::string selectedTileSpriteName = "";
    pen::ui::Item* selectedTileSprite = nullptr;
    int selectedTileSlot = 0;
    pen::Item* currentTile = nullptr;
    bool tileAlt = false;
    /*----Tile Mode----*/

public:
    static PeiselState* Get() {
        if (!instance)
            instance = new PeiselState();
        return instance;
    }
};