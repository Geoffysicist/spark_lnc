// Reclassify land classes to spread model fuel classes

switch(class)
{
    // insert reclass rules here
    case 156:    // Cleared
    case 327:    // Cleared
    case 344:    // Cleared
    case 501:    // Cleared
    case 560:    // Cleared
    case 642:    // Cleared
    case 1038:    // Cleared
    case 515:    // Maritime Grasslands
    case 596:    // Maritime Grasslands
    case 1054:    // Maritime Grasslands
        class = 1;    // fc_grassland
        break;

    case 158:    // Subtropical Rainforests
    case 328:    // Subtropical Rainforests
    case 502:    // Subtropical Rainforests
    case 536:    // Subtropical Rainforests
    case 555:    // Subtropical Rainforests
    case 561:    // Subtropical Rainforests
    case 598:    // Subtropical Rainforests
    case 503:    // Northern Warm Temperate Rainforests
    case 537:    // Northern Warm Temperate Rainforests
    case 556:    // Northern Warm Temperate Rainforests
    case 562:    // Northern Warm Temperate Rainforests
    case 538:    // Cool Temperate Rainforests
    case 557:    // Cool Temperate Rainforests
    case 539:    // Dry Rainforests
    case 558:    // Dry Rainforests
    case 564:    // Dry Rainforests
    case 329:    // Littoral Rainforests
    case 504:    // Littoral Rainforests
    case 559:    // Littoral Rainforests
    case 1040:    // Littoral Rainforests
        class = 5;    // fc_rainforest
        break;

    case 330:    // North Coast Wet Sclerophyll Forests
    case 345:    // North Coast Wet Sclerophyll Forests
    case 505:    // North Coast Wet Sclerophyll Forests
    case 540:    // North Coast Wet Sclerophyll Forests
    case 566:    // North Coast Wet Sclerophyll Forests
    case 599:    // North Coast Wet Sclerophyll Forests
    case 647:    // North Coast Wet Sclerophyll Forests
    case 1041:    // North Coast Wet Sclerophyll Forests
    case 346:    // Northern Escarpment Wet Sclerophyll Forests
    case 541:    // Northern Escarpment Wet Sclerophyll Forests
    case 567:    // Northern Escarpment Wet Sclerophyll Forests
    case 600:    // Northern Escarpment Wet Sclerophyll Forests
    case 542:    // Northern Tableland Wet Sclerophyll Forests
    case 568:    // Northern Tableland Wet Sclerophyll Forests
    case 601:    // Northern Tableland Wet Sclerophyll Forests
    case 333:    // Northern Hinterland Wet Sclerophyll Forests
    case 347:    // Northern Hinterland Wet Sclerophyll Forests
    case 507:    // Northern Hinterland Wet Sclerophyll Forests
    case 543:    // Northern Hinterland Wet Sclerophyll Forests
    case 572:    // Northern Hinterland Wet Sclerophyll Forests
    case 605:    // Northern Hinterland Wet Sclerophyll Forests
    case 657:    // Northern Hinterland Wet Sclerophyll Forests
    case 1044:    // Northern Hinterland Wet Sclerophyll Forests
        class = 4;    // fc_sclerophyll_wet
        break;

    case 331:    // Coastal Dune Dry Sclerophyll Forests
    case 506:    // Coastal Dune Dry Sclerophyll Forests
    case 570:    // Coastal Dune Dry Sclerophyll Forests
    case 603:    // Coastal Dune Dry Sclerophyll Forests
    case 656:    // Coastal Dune Dry Sclerophyll Forests
    case 1042:    // Coastal Dune Dry Sclerophyll Forests
    case 332:    // North Coast Dry Sclerophyll Forests
    case 573:    // Northern Escarpment Dry Sclerophyll Forests
    case 574:    // Northern Tableland Dry Sclerophyll Forests
    case 348:    // Eastern Riverine Forests
    case 583:    // Eastern Riverine Forests
    case 588:    // Northern Gorge Dry Sclerophyll Forests
    case 618:    // Northern Gorge Dry Sclerophyll Forests
    case 326:    // Hunter-Macleay Dry Sclerophyll Forests
    case 339:    // Hunter-Macleay Dry Sclerophyll Forests
    case 349:    // Hunter-Macleay Dry Sclerophyll Forests
    case 511:    // Hunter-Macleay Dry Sclerophyll Forests
    case 591:    // Hunter-Macleay Dry Sclerophyll Forests
        class = 3;    // fc_sclerophyll_dry
        break;

    case 334:    // Wallum Sand Heaths
    case 576:    // Wallum Sand Heaths
    case 1045:    // Wallum Sand Heaths
    case 544:    // Northern Montane Heaths
    case 510:    // Coastal Heath Swamps
    case 584:    // Coastal Heath Swamps
    case 1048:    // Coastal Heath Swamps
    case 340:    // Coastal Headland and Foredune Scrubs
    case 1052:    // Coastal Headland and Foredune Scrubs
        class = 7;    // fc_heath_coastal
        break;

    case 610:    // Tableland Clay Grassy Woodlands
    case 342:    // Coastal Valley Grassy Woodlands
    case 350:    // Coastal Valley Grassy Woodlands
    case 513:    // Coastal Valley Grassy Woodlands
    case 594:    // Coastal Valley Grassy Woodlands
        class = 2;    // fc_woodland
        break;

    case 159:    // Coastal Swamp Forests
    case 335:    // Coastal Swamp Forests
    case 508:    // Coastal Swamp Forests
    case 581:    // Coastal Swamp Forests
    case 1046:    // Coastal Swamp Forests
    case 160:    // Coastal Floodplain Forests
    case 509:    // Coastal Floodplain Forests
    case 582:    // Coastal Floodplain Forests
    case 614:    // Coastal Floodplain Forests
    case 675:    // Coastal Floodplain Forests
    case 597:    // Temperate Swamp Forests
    case 343:    // Floodplain-Estuarine Transition Forests
    case 351:    // Floodplain-Estuarine Transition Forests
        class = 6;    // fc_other_forest
        break;

    case 336:    // Montane Bogs and Fens
        class = 10;    // fc_moorlands
        break;

    case 161:    // Coastal Freshwater Lagoons and Floodplain Meadows
    case 337:    // Coastal Freshwater Lagoons and Floodplain Meadows
    case 1049:    // Coastal Freshwater Lagoons and Floodplain Meadows
    case 211:    // Mangrove Swamps
    case 338:    // Mangrove Swamps
    case 586:    // Mangrove Swamps
    case 681:    // Mangrove Swamps
    case 212:    // Saltmarshes
    case 341:    // Saltmarshes
    case 512:    // Saltmarshes
    case 691:    // Saltmarshes
    case 1053:    // Saltmarshes
    case 213:    // Seagrass Meadows
    case 514:    // Seagrass Meadows
    case 711:    // Seagrass Meadows
        class = 11;    // fc_wetlands
        break;

    default:    // Won't burn or no data
        class = 0;
}