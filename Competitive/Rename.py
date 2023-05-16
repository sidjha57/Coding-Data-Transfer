import os
# Function to rename multiple files
def rename(source_path, dest_path, type_of_haze, i):
	# print(i)
	for files in os.listdir(source_path):
		idx = os.path.splitext(files)[0].split('-')[0]
		idx = str(int(i)+int(idx))
		my_source = source_path + files
		my_dest = dest_path + idx + "-" + type_of_haze + ".png"
		os.rename(my_source, my_dest)


		
# Driver Code
if __name__ == '__main__':

	# thin -> moderate -> thick
	type_of_haze = "thick"
	# train -> valid -> test
	source_name = "/test/target/"
	source_path = "/home/siddharth/Downloads/Compressed/SS594_Multispectral_Dehazing/Haze1k/Haze1k/Haze1k_"+ type_of_haze +"/dataset" + source_name

	dest_name = "/Dehazed/"
	dest_path = "/home/siddharth/Desktop/DataSet" + dest_name 

	i = 800
	# if (len(os.listdir(dest_path)) != 0):
	# 	for files in os.listdir(dest_path):
	# 		idx = os.path.splitext(files)[0].split('-')[0]
	# 		idx = int(idx)
	# 		i = max(i,idx)
	# print(type(i))
	
	rename(source_path, dest_path, type_of_haze, i)
	print("Done Renaming")