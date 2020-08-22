if (class <= 0)  //No Data
{
    class = 0;

}

switch(class)
{
    case 156:    // Cleared
    case 327:    // Cleared
    case 344:    // Cleared
    case 501:    // Cleared
    case 560:    // Cleared
    case 642:    // Cleared
    case 1038:    // Cleared
    case 515:    // MaritimeGrasslands
    case 596:    // MaritimeGrasslands
    case 1054:    // MaritimeGrasslands
        class = 1; // Cleared & Grassland
        break;

    case 610:    // TablelandClayGrassyWoodlands
    case 342:    // CoastalValleyGrassyWoodlands
    case 350:    // CoastalValleyGrassyWoodlands
    case 513:    // CoastalValleyGrassyWoodlands
    case 594:    // CoastalValleyGrassyWoodlands
        class = 2;  // Woodland
        break;
    
    case 331:    // CoastalDuneDrySclerophyllForests
    case 506:    // CoastalDuneDrySclerophyllForests
    case 570:    // CoastalDuneDrySclerophyllForests
    case 603:    // CoastalDuneDrySclerophyllForests
    case 656:    // CoastalDuneDrySclerophyllForests
    case 1042:    // CoastalDuneDrySclerophyllForests
    case 332:    // NorthCoastDrySclerophyllForests
    case 573:    // NorthernEscarpmentDrySclerophyllForests
    case 574:    // NorthernTablelandDrySclerophyllForests
    case 160:    // CoastalFloodplainForests
    case 509:    // CoastalFloodplainForests
    case 582:    // CoastalFloodplainForests
    case 614:    // CoastalFloodplainForests
    case 675:    // CoastalFloodplainForests
    case 348:    // EasternRiverineForests
    case 583:    // EasternRiverineForests
    case 588:    // NorthernGorgeDrySclerophyllForests
    case 618:    // NorthernGorgeDrySclerophyllForests
    case 326:    // Hunter-MacleayDrySclerophyllForests
    case 339:    // Hunter-MacleayDrySclerophyllForests
    case 349:    // Hunter-MacleayDrySclerophyllForests
    case 511:    // Hunter-MacleayDrySclerophyllForests
    case 591:    // Hunter-MacleayDrySclerophyllForests
       class = 3;  // Dry Sclerophyll
        break;

    case 330:    // NorthCoastWetSclerophyllForests
    case 345:    // NorthCoastWetSclerophyllForests
    case 505:    // NorthCoastWetSclerophyllForests
    case 540:    // NorthCoastWetSclerophyllForests
    case 566:    // NorthCoastWetSclerophyllForests
    case 599:    // NorthCoastWetSclerophyllForests
    case 647:    // NorthCoastWetSclerophyllForests
    case 1041:    // NorthCoastWetSclerophyllForests
    case 346:    // NorthernEscarpmentWetSclerophyllForests
    case 541:    // NorthernEscarpmentWetSclerophyllForests
    case 567:    // NorthernEscarpmentWetSclerophyllForests
    case 600:    // NorthernEscarpmentWetSclerophyllForests
    case 542:    // NorthernTablelandWetSclerophyllForests
    case 568:    // NorthernTablelandWetSclerophyllForests
    case 601:    // NorthernTablelandWetSclerophyllForests
    case 333:    // NorthernHinterlandWetSclerophyllForests
    case 347:    // NorthernHinterlandWetSclerophyllForests
    case 507:    // NorthernHinterlandWetSclerophyllForests
    case 543:    // NorthernHinterlandWetSclerophyllForests
    case 572:    // NorthernHinterlandWetSclerophyllForests
    case 605:    // NorthernHinterlandWetSclerophyllForests
    case 657:    // NorthernHinterlandWetSclerophyllForests
    case 1044:    // NorthernHinterlandWetSclerophyllForests
        class = 4;  //  Wet Sclerophyll
        break;
    
    case 334:    // WallumSandHeaths
    case 576:    // WallumSandHeaths
    case 1045:    // WallumSandHeaths
    case 544:    // NorthernMontaneHeaths
    case 510:    // CoastalHeathSwamps
    case 584:    // CoastalHeathSwamps
    case 1048:    // CoastalHeathSwamps
    case 340:    // CoastalHeadlandandForeduneScrubs
    case 1052:    // CoastalHeadlandandForeduneScrubs
        class = 5;  // Coastal Heath
        break;
    
    case 158:    // SubtropicalRainforests
    case 328:    // SubtropicalRainforests
    case 502:    // SubtropicalRainforests
    case 536:    // SubtropicalRainforests
    case 555:    // SubtropicalRainforests
    case 561:    // SubtropicalRainforests
    case 598:    // SubtropicalRainforests
    case 503:    // NorthernWarmTemperateRainforests
    case 537:    // NorthernWarmTemperateRainforests
    case 556:    // NorthernWarmTemperateRainforests
    case 562:    // NorthernWarmTemperateRainforests
    case 538:    // CoolTemperateRainforests
    case 557:    // CoolTemperateRainforests
    case 539:    // DryRainforests
    case 558:    // DryRainforests
    case 564:    // DryRainforests
    case 329:    // LittoralRainforests
    case 504:    // LittoralRainforests
    case 559:    // LittoralRainforests
    case 1040:    // LittoralRainforests
        class = 6; // Rainforest
        break;

    case 159:    // CoastalSwampForests
    case 335:    // CoastalSwampForests
    case 508:    // CoastalSwampForests
    case 581:    // CoastalSwampForests
    case 1046:    // CoastalSwampForests
        class = 7;  // Other Forest
        break;

    case 161:    // CoastalFreshwaterLagoonsandFloodplainMeadows
    case 337:    // CoastalFreshwaterLagoonsandFloodplainMeadows
    case 1049:    // CoastalFreshwaterLagoonsandFloodplainMeadows
    case 211:    // MangroveSwamps
    case 338:    // MangroveSwamps
    case 586:    // MangroveSwamps
    case 681:    // MangroveSwamps
    case 212:    // Saltmarshes
    case 341:    // Saltmarshes
    case 512:    // Saltmarshes
    case 691:    // Saltmarshes
    case 1053:    // Saltmarshes
    case 213:    // SeagrassMeadows
    case 514:    // SeagrassMeadows
    case 711:    // SeagrassMeadows
    case 597:    // TemperateSwampForests
    case 343:    // Floodplain-EstuarineTransitionForests
    case 351:    // Floodplain-EstuarineTransitionForests
        class = 8;  // Wetlands
        break;
    
    case 336:    // MontaneBogsandFens
        class = 11; // Moorlands
        break;

    default:    // Other
        class = 12;
}