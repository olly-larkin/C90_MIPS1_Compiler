x = 0
def main():
	global x
	x = 1
	return x

# Invoke main as the starting point
if __name__ == "__main__": 
	import sys
	ret=main()
	sys.exit(ret)
