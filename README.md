# UAC Test #
uac-test:

A small, simple-ish application to simulate MWO's UAC double-tap.

### Application Usage: ###
    uac-test [uactype] [module] [fastfire] [cycles]

Note: all arguments are required!
    
### Valid Arguments: ###
 
     uactype: 2 | 5 | 10 | 20
      module: 0 | 1
    fastfire: 0 | 1
      cycles: between 1 and 1000000 (upper bound defined in cycle_max)

UAC Type: as described on the tin.

Module: is the cooldown module equipped or not? (Note: UAC2 technically shouldn't have a module.)

Fast Fire: is the Fast Fire skill unlocked or not?

Cycles: number of attempted double-tap cycles.

(Total damage should be at least Cycles * Damage and no greater than 2 * Cycles * Damage.)

### Output: ###
Outputs a file named in such a manner:

    UAC## Module Fastfire NumCycles.csv
    
Example:

    UAC2 noMod FF 100.csv