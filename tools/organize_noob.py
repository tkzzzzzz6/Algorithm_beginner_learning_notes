import os
import shutil
import re

def organize_files():
    # Define the target directory relative to the project root
    base_dir = os.path.join("niuke", "practice", "noob")
    
    # Check if directory exists
    if not os.path.exists(base_dir):
        print(f"Error: Directory {base_dir} does not exist.")
        return

    # Get list of all files in the directory (excluding directories)
    try:
        files = [f for f in os.listdir(base_dir) if os.path.isfile(os.path.join(base_dir, f))]
    except Exception as e:
        print(f"Error listing files: {e}")
        return

    print(f"Found {len(files)} files in {base_dir}. Starting organization...")

    # Loop from 1 to 130
    for i in range(1, 131):
        folder_name = f"noob{i}"
        folder_path = os.path.join(base_dir, folder_name)
        
        # Create the folder if it doesn't exist
        if not os.path.exists(folder_path):
            try:
                os.makedirs(folder_path)
                # print(f"Created directory: {folder_name}")
            except Exception as e:
                print(f"Error creating directory {folder_name}: {e}")
                continue
        
        # Define regex pattern to match files for this number
        # Pattern: starts with "noob" + i + (end of string OR non-digit char)
        # This ensures "noob1" matches "noob1.cpp" but not "noob10.cpp"
        pattern = re.compile(f"^noob{i}(\\D.*)?$")
        
        for filename in files:
            if pattern.match(filename):
                src_path = os.path.join(base_dir, filename)
                dst_path = os.path.join(folder_path, filename)
                
                try:
                    shutil.move(src_path, dst_path)
                    print(f"Moved {filename} -> {folder_name}/")
                except Exception as e:
                    print(f"Error moving {filename}: {e}")

    print("Organization complete.")

if __name__ == "__main__":
    organize_files()
