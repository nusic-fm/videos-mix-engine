#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <utility>

#include "../library/myFFmpegConversion.hpp"
#include "../library/metadataFunction.hpp"
#include "../library/dnaGenerator.hpp"
#include "../library/utils.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

    // GESTIONE LAYER
    const int numbOfPunkToGen = 50;
    const int scale = 240;
    const string outputExtension = ".mov";
    const bool randomized = true;
    // vettore di stringhe che contiene il nome della cartella in cui sono contenuti i singoli layer
    const vector<string> layerDir = {"background", "4", "3", "2", "1"};
    // singoli layer specificati
    const vector<vector<string>> singleLayer =
        {
            {
                "Background-Candy.mov",
                "Background-Dragon-Scales.mov",
                "Background-Fog.mov",
                "Background-Lava.mov",
                "Background-Magic.mov",
                "Background-Midnight.mov",
                "Background-Nusic.mov",
                "Background-Ocean.mov",
                "Background-Peach.mov",
                "Background-Shire.mov",
                "Background-Sky.mov",
                "Background-Treasure.mov",
            },
            {
                "4.1-CATUR-Clé-de-Sol.mov",
                "4.2-CATUR-Clé-de-Fa.mov",
                "4.3-CATUR-Double-croche-Doublet.mov",
                "4.4-CATUR-Croche.mov",
                "4.5-CATUR-Double-croche.mov",
                "4.6-CATUR-Soupir.mov",
            },
            {
                "3.1-TRI-Violinschüssel.mov",
                "3.2-TRI-Bass-schlüssel.mov",
                "3.3-TRI-Sechzehntel-Dublette.mov",
                "3.4-TRI-Achtel.mov",
                "3.5-TRI-Sechzehntel.mov",
                "3.6-TRI-Viertelpause.mov",
            },
            {"2.1-DVI-Chiave-di-Violino.mov", "2.2-DVI-Chiave-di-Basso.mov", "2.3-DVI-Semicroma-Doppietta.mov", "2.4-DVI-Croma.mov", "2.5-DVI-Semicroma.mov", "2.6-DVI-Pausa-di-Semiminima.mov"},
            {
                "1.1-EKA-Treble.mov",
                "1.2-EKA-Bass.mov",
                "1.3-EKA-Sixteenth-Duplet.mov",
                "1.4-EKA-Eighth.mov",
                "1.5-EKA-Sixteenth.mov",
                "1.6-EKA-Quarter-Rest.mov",
            },
        };

    // GESTIONE METADATA
    const vector<vector<string>> singleLayerName =
        {
            {
                "Background-Candy.mov",
                "Background-Dragon Scales.mov",
                "Background-Fog.mov",
                "Background-Lava.mov",
                "Background-Magic.mov",
                "Background-Midnight.mov",
                "Background-Nusic.mov",
                "Background-Ocean.mov",
                "Background-Peach.mov",
                "Background-Shire.mov",
                "Background-Sky.mov",
                "Background-Treasure.mov",
            },
            {
                "EKA Treble.mov",
                "EKA Bass.mov",
                "EKA Sixteenth Duplet",
                "EKA Eighth.mov",
                "EKA Sixteenth.mov",
                "EKA Quoarter Rest.mov",
            },

            {"DVI Chiave di Violino.mov", "DVI Chiave di Basso.mov", "DVI Semicroma Doppietta", "DVI Croma.mov", "DVI Semicroma.mov", "DVI Pausa di Semiminima.mov"},

            {
                "TRI Violinschüssel.mov",
                "TRI Bass-schlüssel.mov",
                "TRI Sechzehntel Dublette",
                "TRI Achtel.mov",
                "TRI Sechzehntel.mov",
                "TRI Viertelpause.mov",
            },

            {
                "CATUR Clé de Sol.mov",
                "CATUR Clé de Fa.mov",
                "CATUR Double-croche Doublet",
                "CATUR Croche.mov",
                "CATUR Double croche.mov",
                "CATUR Soupir.mov",
            }};
    const string name = "NUSIC Governance NFT";
    const string description = "";
    const string image = "";
    const vector<pair<string, string>> extraMetadata =
        {};

    // GESTIONE RARITÀ
    const vector<vector<int>> rarityList =
        {
            {20, 30, 50}, // 3
            {20, 30, 50}, // 3
            {20, 30, 50}, // 3
            {20, 30, 50}, // 3
            {20, 30, 50}, // 3
            {20, 30, 50}, // 3
            {20, 30, 50}  // 3
        };

    if (randomized)
        genAndSaveDnaRandomly("../tmp/punksDna", singleLayer, numbOfPunkToGen);
    else
        genAndSaveDnaWithRarity("../tmp/punksDna", singleLayer, rarityList, numbOfPunkToGen);
    generateAllPunksMetadata(layerDir, singleLayerName, name, description, image, extraMetadata, numbOfPunkToGen);
    createRarityFile(layerDir, singleLayerName, numbOfPunkToGen);
    generateAllPunks(layerDir, singleLayer, numbOfPunkToGen, scale, outputExtension);

    return 0;
}
