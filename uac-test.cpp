#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <tuple>

int main(int argc, char** argv)
{
	int uac;       // UAC class
    int module;    // CD module equipped? (assumes Rank 5: 12%)
    int fastfire;  // Fast Fire unlocked? (5%)
     
    if (argc == 4) {
        uac = strtol(argv[1], NULL, 10);
        module = strtol(argv[2], NULL, 10);
        fastfire = strtol(argv[3], NULL, 10);
    } else {
		std::cout << "Usage: uac-test [uac] [module] [fastfire]" << std::endl;
		std::cout << "Valid Args:" << std::endl;
		std::cout << "     [uac]: 2 | 5 | 10 | 20" << std::endl;
		std::cout << "  [module]: 0 | 1" << std::endl;		
		std::cout << "[fastfire]: 0 | 1" << std::endl;
	}
	
	// Validate UAC selection
	if (uac != 2 && uac != 5 && uac != 10 && uac != 20) {
		std::cout << "Error: [uac] selection must be valid!" << std::endl;
		return 1;
	}
	
	// Validate module flag
	if (module != 0 && module != 1) {
		std::cout << "Error: [module] flag invalid!" << std::endl;
		return 2;
	}
	
	// Validate fastfire flag
	if (fastfire != 0 && fastfire != 1) {
		std::cout << "Error: [fastfire] flag invalid!" << std::endl;
		return 3;
	}
	
	// Format: Weapon (Name, Damage, Cooldown, JamChance);
	std::tuple<std::string, int, float, float> selected;
	std::tuple<std::string, int, float, float> uac2 ("UAC2", 2, 0.72, 0.14);
	std::tuple<std::string, int, float, float> uac5 ("UAC5", 5, 1.66, 0.15);
	std::tuple<std::string, int, float, float> uac10 ("UAC10", 10, 2.5, 0.16);
	std::tuple<std::string, int, float, float> uac20 ("UAC20", 20, 4.0, 0.17);
	
	// Assign UAC
	switch (uac)
	{
	case 2:
		selected = uac2;		
		break;
	case 5:
		selected = uac5;
		break;
	case 10:
		selected = uac10;
		break;
	case 20:
		selected = uac20;
		break;
	}
	
	int damage = std::get<1> (selected);
	double jam_chance = std::get<3> (selected); // use 0 for maximum double-tap rngesus power TROLOLOL ayyylmao
	
	double modifier = 0.0;
	
	if (module) {
		modifier += 0.12;
	}
	
	if (fastfire) {
		modifier += 0.05;
	}
	
	double cooldown = (std::get<2> (selected)) * (1 - modifier);
	
	// Firing Cycles (Rounds/Volleys)
	// ProTip: Pick a large number so that DPS converges and you can excel graph it all pretty-like
	int loop_max = 5000;
	
	std::default_random_engine rand;
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	
	double damage_dealt = 0.0;
	double time_elapsed = 0.0;

	bool stop = false;
	int loop = 0;
	
	std::ofstream logfile;
	std::string name;
	
	// Naming Format "UAC## MOD FF.csv"
	name = std::get<0> (selected);
	
	if (module) {
		name += " Mod";
	} else {
		name += " noMod";
	}
	
	if (fastfire) {
		name += " FF";
	} else {
		name += " noFF";
	}
	
	name += ".csv";

	logfile.open(name);
	logfile << "time,damage,dps" << std::endl;
	
	// Main Firing logic loop
	while (!stop)
	{
		logfile << time_elapsed << "," << damage_dealt << "," << (damage_dealt / time_elapsed) << std::endl;
		
		damage_dealt += damage;
		
		double jam_test;
		jam_test = dist(rand);
		
		if (jam_test > jam_chance) {
			damage_dealt += damage;
			std::cout << "Double Tap!" << std::endl;
		} else {
			// JAMMED!
			// add 5 seconds to time before next cycle
			time_elapsed += 5.0;
			std::cout << "Jammed!" << std::endl;
		}
		
		// cycle weapon
		time_elapsed += cooldown;
		
		if (loop == loop_max) {
			stop = true;
		} else {
			loop++;
		}
	}
	
	logfile.close();	
}
