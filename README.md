# uac-test#
uac-test is a simple, no-frills* command line utility to test DPS for Ultra Autocannons (UACs) in PGI's MechWarrior Online.

*Sorry, I wish it could make you a sandwich, but `sudo`err, I mean `Run as administrator`can only do so much.

## Application Usage: ##
    uac-test [uactype] [module] [fastfire] [cycles]

Note: all arguments are required!
    
## Valid Arguments: ###
 
     uactype: 2 | 5 | 10 | 20
      module: 0 | 1
    fastfire: 0 | 1
      cycles: between 1 and 1000000 (upper bound defined in cycle_max)

UAC Type: as described on the tin.

Module: is the cooldown module equipped or not? (Note: UAC2 technically shouldn't have a module.)

Fast Fire: is the Fast Fire skill unlocked or not?

Cycles: number of attempted double-tap cycles.

(Total damage should be at least Cycles * Damage and no greater than 2 * Cycles * Damage.)

## Output: ##
Outputs a `.csv` based on specified flags:

    UAC## Module Fastfire NumCycles.csv
    
Example:

    UAC2 noMod FF 100.csv

##System Requirements##
* Windows 7 or later (command line yo!)
* Python 3 (for script only)

##Additional Notes##
This project is only meant to be a fun exercise in code (and marginally useful for proving theorycrafting shenanigans) and is intended to be superseded by a GUI version. (Link will be here when available!)
