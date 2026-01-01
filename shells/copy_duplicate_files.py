# -*- coding=utf8 -*-
# Aug 12, 2025
# created by Grok 3
# 复制重复文件以便于备份

import os
import shutil
from pathlib import Path

def copy_duplicate_files(src_dir, tgt_dir, output_dir):
    """
    Copy files from src_dir that have the same name and relative path as files in tgt_dir,
    preserving the directory structure in output_dir.
    
    Args:
        src_dir (str): Source directory path
        tgt_dir (str): Target directory path
        output_dir (str): Output directory to store copied files
    """
    # Convert to Path objects for easier handling
    # 游戏本体文件夹
    src_path = Path(src_dir)
    # mod文件夹
    tgt_path = Path(tgt_dir)
    # 备份文件夹
    output_path = Path(output_dir)
    
    # Create output directory if it doesn't exist
    output_path.mkdir(parents=True, exist_ok=True)
    
    # Walk through tgt_dir to find all files
    for root, _, files in os.walk(tgt_path):
        # Get relative path of current directory
        rel_path = Path(root).relative_to(tgt_path)
        
        # Check each file in tgt_dir
        for file_name in files:
            # Construct corresponding paths
            tgt_file = Path(root) / file_name
            src_file = src_path / rel_path / file_name
            output_file = output_path / rel_path / file_name
            
            # Check if the same file exists in src_dir
            if src_file.is_file():
                # Check if output file already exists
                if output_file.exists():
                    print(f"---Skipped: {output_file} already exists")
                    continue
                # Create output subdirectory if it doesn't exist
                output_file.parent.mkdir(parents=True, exist_ok=True)
                # Copy the file from src to output
                shutil.copy2(src_file, output_file)
                print(f"Copied: {src_file} -> {output_file}")
            else:
                print(f"Skipped: {src_file} does not exist")

if __name__ == "__main__":
    # Example usage
    src_directory = r"E:\Games\Hajimari No Kiseki\data"  # Replace with your src folder path
    tgt_directory = r"E:\Games\Hajimari No Kiseki\mod\[优先]性感\data"  # Replace with your tgt folder path
    output_directory = r"E:\Games\Hajimari No Kiseki\_backup\data"  # Replace with your output folder path
    
    copy_duplicate_files(src_directory, tgt_directory, output_directory)