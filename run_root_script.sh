#!/bin/bash

# Usage check
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 root_script.C input_file_list"
    exit 1
fi

# ROOT script and input file list as arguments
ROOT_SCRIPT=$1
INPUT_FILE_LIST=$2

# Loop through each input file in the list
while IFS= read -r input_file || [[ -n "$input_file" ]]; do
    # Extract the base name of the input file (without extension) to create an output name
    base_name=$(basename "$input_file" .root)
    
    # Define the output file name based on the input file name
    output_file="${base_name}_output.root"

    # Run the ROOT script with the input file and output file
    echo "Processing file: $input_file"
    root -l -b -q "$ROOT_SCRIPT(\"$input_file\", \"$output_file\")"

    echo "Generated output: $output_file"

done < "$INPUT_FILE_LIST"

echo "Processing complete."

