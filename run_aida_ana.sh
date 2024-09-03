#!/bin/bash
#SBATCH --job-name=gains
#SBATCH --nodes=1
#SBATCH --partition=main
#SBATCH --ntasks-per-node=1
#SBATCH --mem-per-cpu=4GB
#SBATCH --cpus-per-task=32
#SBATCH --time=03:00:00
#SBATCH --output=logs/gains.log


export FAIRROOTPATH=/cvmfs/fairsoft.gsi.de/debian11/fairroot/v18.8.0_nov22p1
export SIMPATH=/cvmfs/fairsoft.gsi.de/debian11/fairsoft/nov22p1
export UCESB_DIR=/lustre/gamma/jlarsson/ucesb
export UCESB_BASE_DIR=/lustre/gamma/jlarsson/ucesb

# Se up environment variables for ROOT, FAIRROOT, and other dependencies
export ROOTSYS="${FAIRROOTPATH}"
export PATH="${FAIRROOTPATH}/bin:${SIMPATH}/bin:${UCESB_DIR}/bin:${PATH}"
export LD_LIBRARY_PATH="${FAIRROOTPATH}/lib:${SIMPATH}/lib:${UCESB_DIR}/lib:${LD_LIBRARY_PATH}"

# Source setup scripts
. "${FAIRROOTPATH}/bin/FairRootConfig.sh"
. "${SIMPATH}/bin/thisroot.sh"
. "/lustre/gamma/jlarsson/c4code/virgobuild/config.sh"

#for some reasion thisroot.sh seems to unset some of these guys:
export FAIRROOTPATH=/cvmfs/fairsoft.gsi.de/debian11/fairroot/v18.8.0_nov22p1
export SIMPATH=/cvmfs/fairsoft.gsi.de/debian11/fairsoft/nov22p1
export UCESB_DIR=/lustre/gamma/jlarsson/ucesb
export UCESB_BASE_DIR=/lustre/gamma/jlarsson/ucesb



root -b -l <<EOF
gSystem->AddIncludePath("${FAIRROOTPATH}/include");
gSystem->AddIncludePath("${SIMPATH}/include");

gSystem->AddLinkedLibs("-L/lustre/gamma/jlarsson/c4code/virgobuild/lib -llibc4Analysis.so");  
gSystem->AddLinkedLibs("-L/lustre/gamma/jlarsson/c4code/virgobuild/lib -llibc4Data.so"); 
gSystem->AddLinkedLibs("-L/lustre/gamma/jlarsson/c4code/virgobuild/lib -llibc4MacroCompiler.so"); 
gSystem->AddLinkedLibs("-L/lustre/gamma/jlarsson/c4code/virgobuild/lib -llibc4Base.so"); 

.x /lustre/gamma/jlarsson/S100/gamma/gaindrifts/run_gain_drifts.C
EOF
