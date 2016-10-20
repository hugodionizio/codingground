.data
bitmapdisplay: .space 524288	# Reserve scrn_width * scrn_height * 4 bytes space for the memory mapped bitmap display

filename: .asciiz "demo.bin"

.align 2
scrn_width: .word 512		# Screen Width in Pixels
scrn_height: .word 256		# Screen Height in Pixels

jumptable: .word .m_case0, .m_case1, .m_case2, .m_case3, .m_case4, .m_case5, .m_case6, .m_case7, .m_case8, .m_case9, .m_case10

.text
# Function: void main()
#
# Entry point for the program.
# Reads a descriptor file and dispatches calls the the draw/fill functions.
#
# Local Variables Used:
#
# $s0 = file descriptor
# $s1 = address of switch buffer
#
# $t0 = descriptor number
# $t1 = switch address
#
main:
	li	$v0, 13			# Open existing file
	la	$a0, filename		# Set filename address
	li	$a1, 0			# Set flags = 0
	li	$a2, 0			# Set mode = 0
	syscall
	
	bltz	$v0, .m_exit		# Exit if open file failed
	nop
	
	move	$s0, $v0		# Save file descriptor in $s0
	addiu	$sp, $sp, -4		# Allocate word on the stack for reading switch statement condition
	move	$s1, $sp		# Save pointer to switch buffer in $s1
	
.m_loop:
	move	$a0, $s0		# Read descriptor integer into switch buffer
	move	$a1, $s1
	li	$a2, 4
	li	$v0, 14
	syscall
	
	bltu	$v0, 4, .m_exitloop	# If number bytes read < 4, end of file, exit. Otherwise...
	nop
	
	lw	$t0, ($s1)		# Load the descriptor number into $t0
	bgtu	$t0, 10, .m_exitloop	# If number > 10, invalid descriptor, exit. Otherwise...
	nop
	
	sll	$t0, $t0, 2		# Multiply descriptor number by 4
	lw	$t1, jumptable($t0)	# Read the address to jump to

	jr	$t1			# Jump to case
	nop
	
.m_case0:				# Read setpixel -> (int x, int y, int colour)
	jal	.m_readblock		# (with Branch Delay) Read 12 bytes
	li	$t0, 12			# Branch Delay Slot
	
	lw	$a0, ($sp)		# Load x argument
	lw	$a1, 4($sp)		# Load y argument
	jal	setpixel		# (with Branch Delay) Call setpixel
	lw	$a2, 8($sp)		# Branch Delay Slot: Load colour argument
	
	j	.m_loop			# (with Branch Delay) Break case
	addiu	$sp, $sp, 12		# Branch Delay Slot: Deallocate 3 ints
	
.m_case1:				# Read drawline -> (int x0, int y0, int x1, int y1, int colour)
	jal	.m_readblock		# (with Branch Delay) Read 20 bytes
	li	$t0, 20			# Branch Delay Slot

	lw	$a0,   ($sp)		# Read x0 argument
	lw	$a1,  4($sp)		# Read y0 argument
	lw	$a2,  8($sp)		# Read x1 argument
	lw	$a3, 12($sp)		# Read y1 argument
	lw	$t0, 16($sp)		# Read colour argument to $t0
	addiu	$sp, $sp, -4		# Push colour to stack
	jal	drawline		# (with Branch Delay) Call drawline
	sw	$t0, ($sp)		# Branch Delay Slot
	
	j	.m_loop			# (with Branch Delay) Break case
	addiu	$sp, $sp, 20		# Branch Delay Slot: Deallocate 5 ints

.m_case2:				# Read drawrectangle -> (int x, int y, int width, int height, int colour)
	jal	.m_readblock		# (with Branch Delay) Read 20 bytes
	li	$t0, 20			# Branch Delay Slot
	
	lw	$a0,   ($sp)		# Read x argument
	lw	$a1,  4($sp)		# Read y argument
	lw	$a2,  8($sp)		# Read width argument
	lw	$a3, 12($sp)		# Read height argument
	lw	$t0, 16($sp)		# Read colour argument to $t0
	addiu	$sp, $sp, -4		# Push colour to stack
	jal	drawrectangle		# (with Branch Delay) Call drawline
	sw	$t0, ($sp)		# Branch Delay Slot
	
	j	.m_loop			# (with Branch Delay) Break case
	addiu	$sp, $sp, 20		# Branch Delay Slot: Deallocate 5 ints
	
.m_case3:				# Read drawcircle -> (int cx, int cy, int colour, int radius)
	jal	.m_readblock		# (with Branch Delay) Read 16 bytes
	li	$t0, 16			# Branch Delay Slot
	
	lw	$a0,   ($sp)		# Read cx argument
	lw	$a1,  4($sp)		# Read cy argument
	lw	$a2,  8($sp)		# Read colour argument
	jal	drawcircle		# (with Branch Delay) Call drawline
	lw	$a3, 12($sp)		# Branch Delay Slot: Read radius argument
	
	j	.m_loop			# (with Branch Delay) Break case
	addiu	$sp, $sp, 16		# Branch Delay Slot: Deallocate 5 ints

.m_case4:				# Read drawpolygon -> (int count, int colour, point[] points)
	jal	.m_readblock		# (with Branch Delay) Read 8 bytes
	li	$t0, 8			# Branch Delay Slot

	lw	$s2,   ($sp)		# Read count into $s2
	lw	$s3,  4($sp)		# Read colour into $s3
	
	addiu	$sp, $sp, 8		# Deallocate 2 ints
	
	sll	$s4, $s2, 3		# Multiply count by sizeof(Point) ( = 8). Store in $s4
	jal	.m_readblock		# (with Branch Delay) Read [$s4] bytes
	move	$t0, $s4		# Branch Delay Slot
	
	move	$a0, $sp		# Setup points pointer argument
	move	$a1, $s2		# Setup count argument
	jal	drawpolygon		# (with Branch Delay) Call drawpolygon
	move	$a2, $s3		# Branch Delay Slot: Setup colour argument
	
	j	.m_loop			# (with Branch Delay) Break case
	addu	$sp, $sp, $s4		# Branch Delay Slot: Deallocate [$s4] bytes
	
.m_case5:				# Read fillrectangle -> (int x, int y, int width, int height, int colour)
	jal	.m_readblock		# (with Branch Delay) Read 20 bytes
	li	$t0, 20			# Branch Delay Slot
	
	lw	$a0,   ($sp)		# Read x argument
	lw	$a1,  4($sp)		# Read y argument
	lw	$a2,  8($sp)		# Read width argument
	lw	$a3, 12($sp)		# Read height argument
	lw	$t0, 16($sp)		# Read colour argument to $t0
	addiu	$sp, $sp, -4		# Push colour to stack
	jal	fillrectangle		# (with Branch Delay) Call fillrectangle
	sw	$t0, ($sp)		# Branch Delay Slot
	
	j	.m_loop			# Break case
	addiu	$sp, $sp, 20		# Deallocate 5 ints
	
.m_case6:				# Read fillcircle -> (int x, int y, int radius, int colour)
	jal	.m_readblock		# (with Branch Delay) Read 16 bytes
	li	$t0, 16			# Branch Delay Slot

	lw	$a0,   ($sp)		# Read x argument
	lw	$a1,  4($sp)		# Read y argument
	lw	$a2,  8($sp)		# Read radius argument
	jal	fillcircle		# (with Branch Delay) Call fillcircle
	lw	$a3, 12($sp)		# Branch Delay Slot: Read colour argument

	j	.m_loop			# (with Branch Delay) Break case
	addiu	$sp, $sp, 16		# Branch Delay Slot: Deallocate 5 ints
	
.m_case7:				# Read fillpolygon -> (int count, int colour, Point* points)
	jal	.m_readblock		# (with Branch Delay) Read 8 bytes
	li	$t0, 8			# Branch Delay Slot
	
	lw	$s2,   ($sp)		# Read count into $s2
	lw	$s3,  4($sp)		# Read colour into $s3
	
	addiu	$sp, $sp, 8		# Deallocate 2 ints
	
	sll	$s4, $s2, 3		# Multiply count by sizeof(Point) ( = 8). Store in $s4
	jal	.m_readblock		# (with Branch Delay) Read [$s4] bytes
	move	$t0, $s4		# Branch Delay Slot

	move	$a0, $sp		# Setup points pointer argument
	move	$a1, $s2		# Setup count argument
	li	$a2, 0			# Set mode 0
	jal	fillpolygon		# (with Branch Delay) Call fillpolygon
	move	$a3, $s3		# Branch Delay Slot: Setup colour argument

	j	.m_loop			# (with Branch Delay) Break case
	addu	$sp, $sp, $s4		# Branch Delay Slot: Deallocate [$s4] bytes

.m_case8:				# Read fillpolygon -> (int count, Point* points, int* colours)
	jal	.m_readblock		# (with Branch Delay) Read 4 bytes
	li	$t0, 4			# Branch Delay Slot
	
	lw	$s2,   ($sp)		# Read count into $s2
	addiu	$sp, $sp, 4		# Deallocate 1 int
	
	sll	$s3, $s2, 3		# Multiply count by 8, store in $s3
	sll	$s4, $s2, 2		# Multiply count by 4, store in $s4
	
	addu	$s5, $s3, $s4		# Get total size of points array and colours array
	jal	.m_readblock		# (with Branch Delay) Read that size of bytes
	move	$t0, $s5		# Branch Delay Slot
	
	move	$a0, $sp		# Setup points argument
	move	$a1, $s2		# Setup count argument
	li	$a2, 1			# Setup mode argument
	jal	fillpolygon		# (with Branch Delay) Call fillpolygon
	addu	$a3, $sp, $s3		# Branch Delay Slot: Setup colours argument
	
	j	.m_loop			# (with Branch Delay) Break case
	addu	$sp, $sp, $s5		# Branch Delay Slot: Deallocate points and colours array

.m_case9:				#  Read filltriangle -> (int colour, Point points[3])
	jal	.m_readblock		# (with Branch Delay) Read 28 bytes
	li	$t0, 28			# Branch Delay Slot
	
	addu	$a0, $sp, 4		# Setup points argument
	li	$a1, 0			# Setup mode argument
	jal	filltriangle		# (with Branch Delay) Call filltriangle
	lw	$a2, ($sp)		# Branch Delay Slot: Setup colour argument
	
	j	.m_loop			# (with Branch Delay) Break case
	addiu	$sp, $sp, 28		# Branch Delay Slot: Deallocate colour and points

.m_case10:				# Read filltriangle -> (Point points[3], Colour colours[3])
	jal	.m_readblock		# (with Branch Delay) Read 36 bytes
	li	$t0, 36			# Branch Delay Slot
	
	move	$a0, $sp		# Setup points argument
	li	$a1, 1			# Setup mode argument
	jal	filltriangle		# (with Branch Delay) Call filltriangle
	addiu	$a2, $sp, 24		# Setup colours argument
	
	j	.m_loop			# (with Branch Delay) Break case
	addiu	$sp, $sp, 36		# Branch Delay Slot: Deallocate points and colours array

.m_exitloop:
	addiu $sp, $sp, 4		# Deallocate switch buffer
	
	li $v0, 16			# Close the file
	move $a0, $s0
	syscall

.m_exit:
	li $v0, 10			# Exit the program
	syscall
	
# Helper Function: void m_readblock(int filedescriptor, int size)
#
# Helper function for reading blocks of data from the descriptor file.
# Allocates size bytes on the stack, then attempts to fill the allocated space with
# data from the file. If the file read fails, the space is deallocated, and control is
# jumped to the .m_exitloop label.
# Otherwise, the method returns.
#
# Usage:
#
# $s0 = file descriptor
# $t0 = size
#
.m_readblock:
	subu	$sp, $sp, $t0		# Allocate space on the stack for [size] bytes
	
	move	$a0, $s0		# Setup file descriptor
	move	$a1, $sp		# Setup dest address
	move	$a2, $t0		# Set read length
	li	$v0, 14			# Set ReadFile function index
	syscall				# Read the file
	
	beq 	$v0, $t0, .mrb_readok	# If bytes read < size, end of file or error, exit. Otherwise...
	nop
	
	addu	$sp, $sp, $t0		# Error reading file. Deallocate the space we just made.
	j	.m_exitloop		# Exit the switch loop
	nop
	
.mrb_readok:
	jr	$ra			# Return
	nop

# Function: void setpixel(int x, int y, int colour)
#
# This function sets a single pixel at the given (x,y) coordinates to the colour specified.
# If the pixel is not within the screen bounds, this function has no effect.
#
# Usage:
#
# $a0 = x
# $a1 = y
# $a2 = colour
#
# Returns:
#
# *none*
#
.globl setpixel
setpixel:
	lw	$v0, scrn_width		# Load scrn_width into $v0
	lw	$v1, scrn_height	# Load scrn_height into $v1
					# Drop through into helper function below
	
# Helper Function: void sp_check_set(int x, int y, int colour)
#
# This is a helper function for use by the drawing functions in this file. It does *not* conform to
# standard calling conventions, as it is designed to only be used internally.
# The function sets the pixels at the given (x,y) coordinate to the specified colour, if the pixel
# is on-screen.
#
# Usage:
#
# $t9 = temp     
#
# $a0 = x
# $a1 = y
# $a2 = colour
# $v0 = scrn_width
# $v1 = scrn_height
#
# All registers except $t9 are preserved.
#
.sp_check_set:
	bgeu	$a0, $v0, .sp_exit	# If (x >= scrn_width), exit, otherwise...
	nop
	bgeu	$a1, $v1, .sp_exit	# If (y >=  scrn_height), exit, otherwise...
	nop
	
	mulu	$t9, $v0, $a1		# $t9 = scrn_width * y
	addu	$t9, $t9, $a0		# $t9 += x
	sll	$t9, $t9, 2		# $t9 *= 4
	la	$at, bitmapdisplay	# Load address of bitmap display into $at (compiles to lui -> ori pair, so use of $at is safe)
	addu	$t9, $t9, $at		# Add the bitmap display address to $t9
	
	sw	$a2, ($t9)		# Write the colour value to the bitmap display
	
.sp_exit:
	jr	$ra
	nop

# Function: void drawline(int x0, int y0, int x1, int y1, int colour)
#
# This function draws a single line of pixels between the two points defined by (x0,y0) and (x1,y1)
# using the specified colour, according to the Bresenham Line Algorithm.
#
# Usage:
#
# $a0 = x0
# $a1 = y0
# $a2 = x1
# $a3 = y1
# ($sp) = colour
#
# Returns:
#
# *none*
#
# Local variables used:
#
# $s0 = dx
# $s1 = dy
# $s2 = sx
# $s3 = sy
# $s4 = err
# $s5 = x1     (moved from the $a2 register. frees up $a2 to hold the colour)
# $a2 = colour (loaded from the stack, to replace the x1 argument)
# $v0 = scrn_width
# $v1 = scrn_height
#
.globl drawline
drawline:
	addiu	$sp, $sp, -28			# Save required registers to the stack
	sw	$ra, 24($sp)			# Save return address
	sw	$s5, 20($sp)			# Save $s5
	sw	$s4, 16($sp)			# Save $s4
	sw	$s3, 12($sp)			# Save $s3
	sw	$s2,  8($sp)			# Save $s2
	sw	$s1,  4($sp)			# Save $s1
	sw	$s0,   ($sp)			# Save $s0
	
	lw	$v0, scrn_width			# Load scrn_height into $v0 for later
	lw	$v1, scrn_height		# Load scrn_width into $v1 for later
	
	move	$s5, $a2			# Move x1 to $s5
	lw	$a2, 28($sp)			# Load colour from the stack into $a2
	
	subu	$s0, $s5, $a0			# Calculate dx = x1 - x0, store in $s0
	abs	$s0, $s0			# Get absolute value of dx
	
	subu	$s1, $a3, $a1			# Calculate dy = y1 - y0, store in $s1
	abs	$s1, $s1			# Get absolute value of dy
	
	slt	$s2, $a0, $s5			# Set $s2 (sx) to 1 if x0 < x1, then map 0 to -1 and 1 to 1... 
	sll	$s2, $s2, 1			# Multiply by two
	addiu	$s2, $s2, -1			# Subtract 1
	
	slt	$s3, $a1, $a3			# Set $s3 (sy) to 1 if y0 < y1,m then map 0 to -1 and 1 to 1...
	sll	$s3, $s3, 1			# Multiply by two
	addiu	$s3, $s3, -1			# Subtract 1
	
	subu	$s4, $s0, $s1			# err = dx - dy ($s4 = $s0 - $s1)

.dl_loop:
	jal .sp_check_set			# Call the set pixel helper function
	nop					# All arguments are already setup
	
	sne	$t0, $a0, $s5			# If x0 != x1, set $t0 to 1, otherwise 0
	sne	$t1, $a1, $a3			# If y0 != y1, set $t1 to 1, otherwise 0
	sll	$t1, $t1, 1			# Shift $t1 left by 1
	or	$t0, $t0, $t1			# Or both flags together.
	beqz	$t0, .dl_exit			# If $t0 flag == 0, (x0 == x1 && y0 == y1) == true. The line is complete, so exit the loop
	nop
	
	sll	$t2, $s4, 1			# Set $t2 to $s4 multiplied by 2 (e2 = 2*err)
	subu	$t3, $zero, $s1			# Set $t3 to -dy
	
	ble	$t2, $t3, .dl_skipxadjust	# If e2 > -dy then...
	nop
	
	subu	$s4, $s4, $s1			# err = err - dy
	addu	$a0, $a0, $s2			# x0 = x0 + sx
.dl_skipxadjust:
	
	bge	$t2, $s0, .dl_skipyadjust	# If e2 < dx then...
	nop
	
	addu	$s4, $s4, $s0			# err = err + dx
	addu	$a1, $a1, $s3			# y0 = y0 + sy
.dl_skipyadjust:

	j	.dl_loop			# Loop
	nop
	
.dl_exit:
	lw	$s0,   ($sp)			# Restore $s0
	lw	$s1,  4($sp)			# Restore $s1
	lw	$s2,  8($sp)			# Restore $s2
	lw	$s3, 12($sp)			# Restore $s3
	lw	$s4, 16($sp)			# Restore $s4
	lw	$s5, 20($sp)			# Restore $s5
	lw	$ra, 24($sp)			# Restore return address
	jr	$ra				# (with Branch Delay) Return
	addiu	$sp, $sp, 32			# Branch Delay Slot: Adjust stack pointer to pop registers, and colour parameter off the stack

# Function: void drawrectangle(int x, int y, int width, int height, int colour)
#
# This function draws a single rectangle with its top left corner at the point (x,y), with the given
# width and height, using the given colour.
# The rectangle is clipped if part of it exceeds the screen bounds.
#
# Usage:
#
# $a0 = x
# $a1 = y
# $a2 = width
# $a3 = height
# ($sp) = colour
#
# Returns:
#
# *none*
#
# Local Variables Used:
#
# $t0 = original x
# $t1 = original y
# $t2 = p1 x
# $t3 = p1 y
# $a2 = colour (copied from the stack for .sp_check_set helper method)
#
.globl drawrectangle
drawrectangle:
	addiu	$sp, $sp, -4		# Save return address to the stack
	sw	$ra, ($sp)
	
	beqz	$a2, .dr_exit		# Exit if width == 0
	nop
	beqz	$a3, .dr_exit		# Exit if height == 0
	nop
	
	move	$t0, $a0		# Save x in $t0 for later
	move	$t1, $a1		# Save y in $t1 for later
	move	$t2, $a2		# Save width in $t2 for later
	move	$t3, $a3		# Save height in $t3 for later
	
	addu	$t2, $t2, $t0		# Add original x to width to get p1 x
	addu	$t3, $t3, $t1		# Add original y to height to get p1 y
	
	addiu	$t2, $t2, -1		# Decremnt p1 x
	addiu	$t3, $t3, -1		# Decrement p1 y
	
	lw	$v0, scrn_width		# Load screen width into $v0 for .sp_check_set
	lw	$v1, scrn_height	# Load screen height into $v1 for .sp_check_set
	
	jal	.sp_check_set		# (with Branch Delay) Draw the first pixel (handles the case where width and height equal 1)
	lw	$a2, 4($sp)		# Branch Delay Slot: Load the colour from the stack into $a2
	
.dr_line1:
	bge 	$a0, $t2, .dr_line2	# If the first line is complete (x >= p1 x), goto the second line, otherwise...
	nop
	jal	.sp_check_set		# Draw the current pixel
	nop
	j	.dr_line1		# (with Branch Delay) Loop
	addiu	$a0, $a0, 1		# Branch Delay Slot: Increment x
	
.dr_line2:
	bge	$a1, $t3, .dr_line3	# If the second line is complete (y >= p1 y), goto the third line, otherwise...
	nop
	jal	.sp_check_set		# Draw the current pixel
	nop
	j	.dr_line2		# (with Branch Delay) Loop
	addiu	$a1, $a1, 1		# Branch Delay Slot: Increment y
	
.dr_line3:
	ble	$a0, $t0, .dr_line4	# If the thrid line is complete (x <= original x), goto the third line, otherwise...
	nop
	jal	.sp_check_set		# Draw the current pixel
	nop
	j	.dr_line3		# (with Branch Delay) Loop
	addiu	$a0, $a0, -1		# Branch Delay Slot: Decrement x

.dr_line4:
	ble	$a1, $t1, .dr_exit	# If the last line is complete (y <= original y), exit, otherwise...
	nop
	jal	.sp_check_set		# Draw the current pixel
	nop
	j	.dr_line4		# (with Branch Delay) Loop
	addiu	$a1, $a1, -1		# Branch Delay Slot: Decrement y

.dr_exit:
	lw	$ra, ($sp)		# Restore the return address
	jr	$ra			# (with Branch Delay) Return
	addiu	$sp, $sp, 8		# Branch Delay Slot: Pop colour argument off the stack

# Function: void drawcircle(int cx, int cy, int colour, int radius)
#
# This function draws a single circle, with the given radius, centered
# around the point (cx,cy) using the given colour. The circle is clipped if part of it
# crosses the screen boundary.
#
# Usage:
#
# $a0 = cx
# $a1 = cy
# $a2 = colour
# $a3 = radius
#
# Returns:
#
# *none*
#
# Local Variables Used:
#
# $s0 = error
# $s1 = x
# $s2 = y
# $s3 = cx
# $s4 = cy
#
.globl drawcircle
drawcircle:
	bnez	$a3, .dc_radiusnonzero	# Check if the radius is non-zero
	nop
	jr	$ra			# Cannot draw a 0 radius circle, just return now
	nop

.dc_radiusnonzero:
	addiu	$sp, $sp, -24		# Save $sx and $ra registers to the stack
	sw	$ra, 20($sp)
	sw	$s4, 16($sp)
	sw	$s3, 12($sp)
	sw	$s2,  8($sp)
	sw	$s1,  4($sp)
	sw	$s0,   ($sp)
	
	lw	$v0, scrn_width		# Load scrn_width into $v0 for .sp_check_set helper later
	lw	$v1, scrn_height	# Load scrn_height into $v1 for .sp_check_set helper later
	
	move	$s3, $a0		# Save cx in $s3
	move	$s4, $a1		# Save cy in $s4
	
	subu	$s0, $zero, $a3		# Set error = -radius ($s0 = 0 - $a2)
	move	$s1, $a3		# Set x = radius ($s1 = $a2)
	li	$s2, 0			# Initialize y to 0 ($s2 = 0)
	
.dc_loop:
	bltu	$s1, $s2, .dc_exit	# Break loop if x < y
	nop
	
	jal	.dc_drawpoints		# Call .dc_drawpoints
	nop
	
	beq	$s1, $s2, .dc_skipplot	# If x != y then...
	nop
	
	move	$t0, $s1		# Swap x and y
	move	$s1, $s2
	move	$s2, $t0
	jal	.dc_drawpoints		# Call .dc_drawpoints
	nop
	
	move	$t0, $s1		# Swap x and y back
	move	$s1, $s2
	move	$s2, $t0
.dc_skipplot:
	
	addu	$s0, $s0, $s2		# Add y to error ($s0 += $s2)
	addiu	$s2, $s2, 1		# Increment y
	addu	$s0, $s0, $s2		# Add y to error ($s0 += $s2)
	
	bltz	$s0, .dc_skipxadjust	# If error >= 0 then...
	nop
	
	addiu	$s1, $s1, -1		# Decrement x
	subu	$s0, $s0, $s1		# Subtract x from error ($s0 -= $s1)
	subu	$s0, $s0, $s1		# Subtract x from error ($s0 -= $s1)

.dc_skipxadjust:
	j	.dc_loop		# Loop
	nop
	
.dc_exit:
	lw	$s0,   ($sp)
	lw	$s1,  4($sp)
	lw	$s2,  8($sp)
	lw	$s3, 12($sp)
	lw	$s4, 16($sp)
	lw	$ra, 20($sp)
	jr	$ra			# (with Branch Delay) Return
	addiu	$sp, $sp, 24		# Branch Delay Slot: Adjust stack pointer to pop registers


.dc_drawpoints:				# Helper routine used in drawcircle
	move	$t0, $ra		# Save return address in $t0 (more optimal than saving to stack)
	
	addu	$a0, $s3, $s1		# x coord = cx + x ($a0 = $s3 + $s1)
	jal	.sp_check_set		# (with Branch Delay) Call .sp_check_set
	addu	$a1, $s4, $s2		# Branch Delay Slot: y coord = cy + y ($a1 = $s4 + $s2)

	subu	$a0, $s3, $s1		# x coord = cx - x ($a0 = $s3 - $s1)
	jal	.sp_check_set		# (with Branch Delay) Call .sp_check_set
	subu	$a1, $s4, $s2		# Branch Delay Slot: y coord = cy - y ($a1 = $s4 - $s2)

	beqz	$s1, .dcdp_skipxplot	# If x != 0 then...
	nop
	
	subu	$a0, $s3, $s1		# x coord = cx - x ($a0 = $s3 - $s1)
	jal	.sp_check_set		# (with Branch Delay) Call .sp_check_set
	addu	$a1, $s4, $s2		# y coord = cy + y ($a1 = $s4 + $s2)
	
.dcdp_skipxplot:
	
	beqz	$s2, .dcdp_skipyplot	# If y != 0 then...
	nop
	
	addu	$a0, $s3, $s1		# x coord = cx + x ($a0 = $s3 + $s1)
	jal	.sp_check_set		# (with Branch Delay) Call .sp_check_set
	subu	$a1, $s4, $s2		# Branch Delay Slot: y coord = cy - y ($a1 = $s4 - $s2)
	
.dcdp_skipyplot:
	jr	$t0			# Return using the saved address in $s7
	nop
	
# Function: void drawpolygon(point[] points, int count, int colour)
#
# This function draws a polygon defined by a list of points using the specified colour.
# The memory address to an array of point structures is passed in the "points" argument.
# The number of point structures is passed in the "count" argument.
# The struct is defined as follows:
#
# struct point {
# 	int x;
# 	int y;
# }
#
# Usage:
#
# $a0 = pointer to an array of points stored in memory
# $a1 = count
# $a2 = colour
#
# Returns:
#
# *none*
#
# Local Variables Used:
#
# $s0 = points address
# $s1 = count
# $s2 = colour
# $s3 = loop counter
#
.globl drawpolygon
drawpolygon:
	addiu	$sp, $sp, -20	# Store return address and $sx register on the stack
	sw	$ra, 16($sp)
	sw	$s0, 12($sp)
	sw	$s1,  8($sp)
	sw	$s2,  4($sp)
	sw	$s3,   ($sp)
	
	move	$s0, $a0	# Preserve the points address in $s0
	move	$s1, $a1	# Preserve the count value in $s1
	move	$s2, $a2	# Preserve the colour in $s2
	li	$s3, 0		# Initialize the loop counter to 0
	
.dp_loop:
	sll	$t0, $s3, 3	# Multiply the counter by 8 to get the byte index of the current point
	addu	$t1, $s0, $t0	# Calculate the base address of the current point, store in $t1

	lw	$a0,  ($t1)	# Load x0 from struct
	lw	$a1, 4($t1)	# Load y0 from struct
	
	addiu	$s3, $s3, 1	# Increment the point counter
	div	$s3, $s1	# Wrap from count to 0 using modulus division
	mfhi	$s3		# Move remainder into point counter
	
	sll	$t0, $s3, 3	# Multiply the counter by 8 to get the byte index of the next point
	addu	$t1, $s0, $t0	# Calculate the base address of the next point, store in $t1
	
	lw	$a2,  ($t1)	# Load x1 from struct
	lw	$a3, 4($t1)	# Load y1 from struct
	
	addiu	$sp, $sp, -4	# Push the colour to the stack
	jal	drawline	# (with Branch Delay) Call drawline
	sw	$s2, ($sp)	# Branch Delay Slot: Finish pushing colour to the stack
	
	bnez	$s3, .dp_loop	# If counter != 0, more points to draw, so loop back
	nop
	
	lw	$s3,   ($sp)	# Restore the return address and $sx registers
	lw	$s2,  4($sp)
	lw	$s1,  8($sp)
	lw	$s0, 12($sp)
	lw	$ra, 16($sp)
	jr	$ra		# (with Branch Delay) Return
	addiu	$sp, $sp, 20	# Branch Delay Slot: Adjust stack pointer to pop saved registers

# Function: void fillrectangle(int x, int y, int width, int height, int colour)
#
# This function fills a single rectangle with its top left corner at the point (x,y), with the given
# width and height, using the given colour.
# The rectangle is clipped if part of it exceeds the screen bounds.
#
# Usage:
#
# $a0 = x
# $a1 = y
# $a2 = width
# $a3 = height
# ($sp) = colour
#
# Returns:
#
# *none*
#
# Local Variables Used:
#
# $t0 = scrn_width / j
# $t1 = scrn_height
# $t2 = x2
# $t3 = y2
# $t4 = row start address
# $t5 = current pixel address
# $t6 = row span size
# $t8 = i
# $t9 = colour
#
.globl fillrectangle
fillrectangle:
	lw	$t0, scrn_width			# Load scrn_width into $t0 for clamp calculations
	lw	$t1, scrn_height		# Load scrn_height into $t1 for clamp calculations
	
	bge	$a0, $t0, .fr_exit		# (with Branch Delay) Exit if x >= scrn_width
	lw	$t9, ($sp)			# Branch Delay Slot: Load colour into $t9 for pixel rendering later
	
	bge	$a1, $t1, .fr_exit		# Exit if y >= scrn_height
	nop
	
	beqz	$a2, .fr_exit			# (with Branch Delay) Exit if width == 0
	addu	$t2, $a0, $a2			# Branch Delay Slot: $t2 = x + width (no side-effects if branch is taken)
	
	beqz	$a3, .fr_exit			# (with Branch Delay) Exit if height == 0
	addu	$t3, $a1, $a3			# Branch Delay Slot: $t3 = y + height (no side-effects if branch is taken)
	
	bltz	$t2, .fr_exit			# Exit if (x + width) < 0
	nop
	bltz	$t3, .fr_exit			# Exit if (y + height) < 0
	nop
	
	bgez	$a0, .fr_skipxclamp		# Clamp x to >= 0
	nop
	li	$a0, 0
.fr_skipxclamp:
	
	bgez	$a1, .fr_skipyclamp		# Clamp y to >= 0
	nop
	li	$a1, 0
.fr_skipyclamp:

	blt	$t2, $t0, .fr_skipx2clamp	# Clamp x2 to <= scrn_width
	nop
	move	$t2, $t0
.fr_skipx2clamp:

	blt	$t3, $t1, .fr_skipy2clamp	# Clamp y2 to <= scrn_height
	nop
	move	$t3, $t1
.fr_skipy2clamp:

	subu	$a2, $t2, $a0			# Calculate new clamped width
	subu	$a3, $t3, $a1			# Calculate new clamped height
	
	# x, y, width and height are all now within the bounds of the screen
	# start filling
	
	# $t0 = j
	# $t4 = row start address
	# $t5 = current pixel address
	# $t6 = row span size
	# $t8 = i
	
	sll	$t6, $t0, 2			# row span = scrn_width * 4

						# Calculate row start address
	mul	$t4, $a1, $t0			# $t4 = y * scrn_width
	addu	$t4, $t4, $a0			# $t4 += x
	sll	$t4, $t4, 2			# $t4 *= 4
	la	$t7, bitmapdisplay
	addu	$t4, $t4, $t7			# $t4 += bitmapdisplay address
	
	li	$t0, 0				# j = 0

.fr_outerloop:
	move	$t5, $t4			# Set current pixel address to the start address of this row
	li	$t8, 0				# i = 0
	
.fr_innerloop:
	bgeu	$t8, $a2, .fr_exitinner		# If i >= width, break inner loop, otherwise...
	nop
	
	sw	$t9, ($t5)			# Write pixel color to current pixel
	addiu	$t5, $t5, 4			# Increment pixel address by 4
	addiu	$t8, $t8, 1			# Increment i by 1
	j	.fr_innerloop			# Loop
	nop
	
.fr_exitinner:
	addu	$t4, $t4, $t6			# row start address += row span size
	addiu	$t0, $t0, 1			# Increment j
	
	blt	$t0, $a3, .fr_outerloop		# If j < height, loop, otherwise exit...
	nop

.fr_exit:
	jr	$ra				# (with Branch Delay) Return
	addiu	$sp, $sp, 4			# Branch Delay Slot: Pop colour from stack
	
# Function: void fillcircle(int x, int y, int radius, int colour)
#
# This function draws a solid filled circle, with the given radius and colour, centered about
# the point (x,y).
#
# Usage:
#
# $a0 = x
# $a1 = y
# $a2 = radius
# $a3 = colour
#
# Returns:
#
# *none*
#
# Local Variables Used:
#
# $s0 = xoff
# $s1 = yoff
# $s2 = balance
# $s3 = p0
# $s4 = p1
# $s5 = w0
# $s6 = w1
# $s7 = colour
#
.globl fillcircle
fillcircle:
	addiu	$sp, $sp, -44		# Save $ra and $sx registers
	sw	$ra, 40($sp)
	sw	$s7, 36($sp)
	sw	$s6, 32($sp)
	sw	$s5, 28($sp)
	sw	$s4, 24($sp)
	sw	$s3, 20($sp)
	sw	$s2, 16($sp)
	sw	$s1, 12($sp)
	sw	$s0, 8($sp)
	
	sw	$a1, 4($sp)		# Save y to the stack for later
	sw	$a0, ($sp)		# Save x to the stack for later
	
	li	$s0, 0			# Initialize xoff to 0
	move	$s1, $a2		# Initialize yoff with radius
	subu	$s2, $zero, $s1		# Initialize balance with -radius
	move	$s7, $a3		# Preserve colour in $s7

	lw	$v0, scrn_width		# Load $v0 with scrn_width for .sp_check_set
	lw	$v1, scrn_height	# Load $v1 with scrn_height for .sp_check_set

.fc_loop:
	bgtu	$s0, $s1, .fc_exit	# Exit loop if xoff > yoff
	nop
	
	lw	$t0, ($sp)		# Load x into $t0
	subu	$s3, $t0, $s0		# p0 = x - xoff
	subu	$s4, $t0, $s1		# p1 = x - yoff
	
	addu	$s5, $s0, $s0		# w0 = xoff + xoff
	addu	$s6, $s1, $s1		# w1 = yoff + yoff
	
	# calls to hline here
	# registers $sx, $t0, $t1, $t2, and $t3 are preserved by fc_hline
	lw	$t3, 4($sp)		# Load y into $t9 (used in the argument calculations)
	
	# First Line
	move	$t0, $s3		# argument xp = p0
	addu	$t1, $t3, $s1		# argument yp = y + yoff
	jal	.fc_hline		# (with Branch Delay) Call .fc_hline
	move	$t2, $s5		# Branch Delay Slot: argument w = w0
	
	# Second Line
	jal	.fc_hline		# (with Branch Delay) Call .fc_hline
	subu	$t1, $t3, $s1		# Branch Delay Slot: argument yp = y - yoff, all other arguments persist from last call
	
	# Third Line
	move	$t0, $s4		# argument xp = p1
	addu	$t1, $t3, $s0		# argument yp = y + xoff
	jal	.fc_hline		# (with Branch Delay) Call .fc_hline
	move	$t2, $s6		# argument w = w1
	
	# Fourth Line
	jal	.fc_hline		# (with Branch Delay) Call .fc_hline
	subu	$t1, $t3, $s0		# Branch Delay Slot: argument yp = y - xoff, all other arguments persist from last call
	
	# end of hline calls
	
	addu	$s2, $s2, $s5		# balance += xoff + xoff (which is w0, stored in $s5)
	addiu	$s0, $s0, 1		# Increment xoff
	bltz	$s2, .fc_skipyadj	# If balance >= 0 then...
	nop
	addiu	$s1, $s1, -1		# Decrement yoff
	addu	$t0, $s1, $s1		# $t0 = yoff + yoff
	subu	$s2, $s2, $t0		# balance -= $t0
.fc_skipyadj:
	j	.fc_loop		# Loop
	nop
	
.fc_exit:
	lw	$ra, 40($sp)		# Restore $ra and $sx registers from the stack
	lw	$s7, 36($sp)
	lw	$s6, 32($sp)
	lw	$s5, 28($sp)
	lw	$s4, 24($sp)
	lw	$s3, 20($sp)
	lw	$s2, 16($sp)
	lw	$s1, 12($sp)
	lw	$s0, 8($sp)
	jr	$ra			# (with Branch Delay) Return
	addiu	$sp, $sp, 44		# Branch Delay Slot: Adjust the stack pointer to remove $ra, $sx and x,y arguments
	
.fc_hline:				# Helper routine for fill circle, draws a horizontal line from (xp, yp) to (xp+w, yp)
	# Input:
	# $t0 = xp
	# $t1 = yp
	# $t2 = w
	# $s7 = colour
	addiu	$sp, $sp, -24
	sw	$s2,   ($sp)		# Move balance onto the stack to free up $s2
	sw	$t0,  4($sp)		# Save xp to the stack
	sw	$t1,  8($sp)		# Save yp to the stack
	sw	$t2, 12($sp)		# Save w to the stack
	sw	$t3, 16($sp)		# Preserve a register for use in the parent function
	sw	$ra, 20($sp)		# Save return address to the stack
	
	# $s2 = i
	li	$s2, 0			# Initialize loop counter to 0
	
.fc_hlineloop:
	lw	$t2, 12($sp)		# Reload w to $t2, incase it was change by setpixel call
	bgeu	$s2, $t2, .fc_hlineexit	# Break if i >= w
	nop
	
	lw	$t0, 4($sp)		# Reload xp to $t0
	addu	$a0, $t0, $s2		# Set $a0 to xp + i (x argument for setpixel)
	lw	$a1, 8($sp)		# Load $a1 with yp (y argument for setpixel)
	jal	.sp_check_set		# Call set pixel (but set colour in branch delay slot first)
	move	$a2, $s7		# Branch Delay Slot: Copy colour into $a2 (colour argument for setpixel)
	
	j	.fc_hlineloop		# (with Branch Delay) Loop
	addiu	$s2, $s2, 1		# Branch Delay Slot: Increment i

.fc_hlineexit:
	lw	$s2,   ($sp)		# Restore balance from the stack
	lw	$t0,  4($sp)		# Restore xp from the stack
	lw	$t1,  8($sp)		# Restore yp from the stack
	lw	$t2, 12($sp)		# Restore w from the stack
	lw	$t3, 16($sp)		# Restore the reserved register for use in the parent function
	lw	$ra, 20($sp)		# Restore return address from the stack
	jr	$ra			# (with Branch Delay) Return
	addiu	$sp, $sp, 24		# Branch Delay Slot: Adjust stack pointer

# Function: void fillpolygon(Point* points, int count, int mode, ...)
#
# Mode 0: void fillpolygon(Point* points, int count, 0, Colour colour)
# Mode 1: void fillpolygon(Point* points, int count, 1, Colour* colours)
#
# This function fills a polygon defined by an array of points, of count length.
# The shading method is determined by the mode parameter.
#
# In Mode 0, the contents of $a2 is treated as a single 0xAARRGGBB colour value, and the polygon is shaded
# with a solid colour.
#
# In Mode 1, the contents of $a2 is treated as a pointer to an array of colours, of length count, one colour per vertex.
# The colours are blended across the polygon to produce a gradient.
#
# If mode is an invalid value, this function returns with no effect.
#
# Usage:
#
# $a0 = points
# $a1 = count
# $a2 = mode
# $a3 = colour / colours pointer
#
# Returns:
#
# *none*
#
# Local Variable Used:
#
# $s0 = points
# $s1 = count
# $s2 = mode
# $s3 = colour / colours pointer
# $s4 = &stackPoints[3]
# $s5 = &stackColours[3]
# $s6 = i
#
.globl fillpolygon
fillpolygon:
	addiu	$sp, $sp, -32		# Save return address and $sx registers to the stack
	sw	$ra, 28($sp)
	sw	$s6, 24($sp)
	sw	$s5, 20($sp)
	sw	$s4, 16($sp)
	sw	$s3, 12($sp)
	sw	$s2,  8($sp)
	sw	$s1,  4($sp)
	sw	$s0,   ($sp)

	bgeu	$a2, 2, .fp_exit	# (with Branch Delay) Exit if mode is invalid
	move	$s0, $a0		# Branch Delay Slot: Save points to $s0 for later (if branch is taken, $s0 is restored)
	bltu	$a1, 3, .fp_exit	# (with Branch Delay) Exit if count is less than 3
	move	$s1, $a1		# Branch Delay Slot: Save count to $s1 for later (if branch is taken, $s1 is restored)
	
	move	$s2, $a2		# Save mode to $s2 for later
	move	$s3, $a3		# Save colour / pointer to $s3 for later
	
	addiu	$sp, $sp, -24		# Allocate an array of 3 Point structures on the stack
	move	$s4, $sp		# Save pointer to array in $s4
	
	lw	$t0,   ($s0)		# Copy first x value to the stackPoints array
	sw	$t0,   ($s4)
	lw	$t0,  4($s0)		# Copy first y value to the stackPoints array
	
	beqz	$s2, .fp_skipcolalloc	# (with Branch Delay) If this is not mode 1, skip allocating a colour array on the stack
	sw	$t0,  4($s4)		# Branch Delay Slot: Finish y copy
	
	addiu	$sp, $sp, -12		# Allocate an array of 3 Colour structures on the stack
	move	$s5, $sp		# Save pointer to array in $s5
	
	lw	$t0,   ($s3)		# Copy first colour to the stackColours array
	sw	$t0,   ($s5)
	
	addiu	$s3, $s3, 4		# Increment colour pointer by sizeof(Colour)
	
.fp_skipcolalloc:

	li	$s6, 2			# Initialize i to 2
	addiu	$s0, $s0, 8		# Increment points by sizeof(Point)
	
.fp_loop:
	lw	$t0,   ($s0)		# Copy points->x to stackPoints[1].x
	sw	$t0,  8($s4)
	lw	$t0,  4($s0)		# Copy points->y to stackPoints[1].y
	sw	$t0, 12($s4)
	
	addiu	$s0, $s0, 8		# Increment points by sizeof(Point)
	
	lw	$t0,   ($s0)		# Copy points->x to stackPoints[2].x
	sw	$t0, 16($s4)
	lw	$t0,  4($s0)		# Copy points->y to stackPoints[2].y
	sw	$t0, 20($s4)
	
	beqz	$s2, .fp_skipcolcopy	# (with Branch Delay) If this is not mode 1, skip copying the colour array
	move	$a2, $s3		# Branch Delay Slot: Set colour argument (gets overwritten if in mode 1  by following code)
	
	lw	$t0,  ($s3)		# Copy first colour to stackColours[1]
	sw	$t0, 4($s5)
	lw	$t0, 4($s3)		# Copy second colour to stackColours[2]
	sw	$t0, 8($s5)
	
	move	$a2, $s5		# Set colour argument to &stackColours[0]
	addiu	$s3, $s3, 4		# Increment colours pointer by sizeof(Colour)
.fp_skipcolcopy:
	
	move	$a0, $s4		# Setup points argument
	jal	filltriangle
	move	$a1, $s2		# Setup mode argument
	
	addiu	$s6, $s6, 1		# Increment i
	bltu	$s6, $s1, .fp_loop	# If i < count, loop
	nop
	
	beqz	$s2, .fp_exit		# (with Branch Delay) If this is not mode 1, skip deallocating the colour array
	addiu	$sp, $sp, 24		# Branch Delay Slot: Deallocate stackPoints array
	addiu	$sp, $sp, 12		# Deallocate the array of 3 Colour structures on the stack
	
.fp_exit:
	lw	$s0,   ($sp)		# Restore $sx and $ra registers from the stack
	lw	$s1,  4($sp)
	lw	$s2,  8($sp)
	lw	$s3, 12($sp)
	lw	$s4, 16($sp)
	lw	$s5, 20($sp)
	lw	$s6, 24($sp)
	lw	$ra, 28($sp)
	jr	$ra			# (with Branch Delay) Return
	addiu	$sp, $sp, 32		# Branch Delay Slot: Save return address and $sx registers to the stack
	

# Function: void filltriangle(Point points[3], int mode, ...)
#
# Mode 0: void filltriangle(Point points[3], 0, Colour colour)
# Mode 1: void filltriangle(Point points[3], 1, Colour colours[3])
#
# This function fills a single triangle defined by 3 points, passed as an array into points.
# The shading method is determined by the mode parameter.
#
# In Mode 0, the contents of $a2 is treated as a single 0xAARRGGBB colour value, and the triangle is shaded
# with a solid colour.
#
# In Mode 1, the contents of $a2 is treated as a pointer to an array of colours, of length 3, one colour per vertex.
# The colours are blended across the triangle to produce a gradient.
#
# If mode is an invalid value, this function returns with no effect.
#
# Usage:
#
# $a0 = points
# $a1 = mode
# $a2 = colour / colour pointer
# 
# Returns:
#
# *none*
#
# Local Variables Used:
# 
# $s0 = Point* A  /  loop line 1 pointer
# $s1 = Point* B  /  loop line 2 pointer
# $s2 = Point* C  /  "is first loop" flag
# $s3 = uvDenominator
# $s4 = line 1 segment x
# $s5 = points pointer
# $s6 = colours pointer
# $s7 = mode
#
.globl filltriangle
filltriangle:
	addiu	$sp, $sp, -36		# Save $sx and $ra registers to the stack
	sw	$ra, 32($sp)		# Save $ra
	sw	$s7, 28($sp)		# Save $s7
	sw	$s6, 24($sp)		# Save $s6
	sw	$s5, 20($sp)		# Save $s5
	sw	$s4, 16($sp)		# Save $s4
	sw	$s3, 12($sp)		# Save $s3
	sw	$s2,  8($sp)		# Save $s2
	sw	$s1,  4($sp)		# Save $s1
	sw	$s0,  0($sp)		# Save $s0
	
	bgeu	$a1, 2, .ft_exit	# (with Branch Delay) Exit if mode is an invalid value
	move	$s0, $a0		# Branch Delay Slot: Copy pointer to first point into A ($s0) (if branch is taken, value in $s0 is restored later)
	addiu	$s1, $s0, 8		# Calcualte pointer to second point, store in B ($s1)
	addiu	$s2, $s1, 8		# Calculate pointer to third point, store in C ($s2)
	
	move	$s5, $a0		# Save original array pointer for later
	move	$s6, $a2		# Save colour pointer / colour in $s6 for later
	move	$s7, $a1		# Save mode for later
	
.ft_sortloop:
	lw	$t0, 4($s0)		# Load A->y into $t0
	lw	$t1, 4($s1)		# Load B->y into $t1
	
	bge	$t1, $t0, .ft_skipabswap# If B.y >= A.y, skip A<->B swap, otherwise:
	nop
	
	move	$t2, $s0		# Swap registers $s0 and $s1, using $t2
	move	$s0, $s1
	move	$s1, $t2
	
.ft_skipabswap:
	lw	$t0, 4($s1)		# Load B->y into $t0
	lw	$t1, 4($s2)		# Load C->y into $t1
	
	bge	$t1, $t0, .ft_skipcbswap# If C.y >= B.y, skip C<->B swap, otherwise:
	nop
	
	move	$t2, $s1		# Swap registers $s1, and $s2, using $t2
	move	$s1, $s2
	j	.ft_sortloop		# Loop back (with delay slot)
	move	$s2, $t2		# Branch Delay Slot: final movement for register swap

.ft_skipcbswap:				# Sorting done, A.y <= B.y <= C.y

	# Calculate the uvDenominator value for drawhline
	lw	$t0,   ($s5)		# Load A.x into $t0
	lw	$t1,  4($s5)		# Load A.y into $t1
	lw	$t2,  8($s5)		# Load B.x into $t2
	lw	$t3, 12($s5)		# Load B.y into $t3
	lw	$t4, 16($s5)		# Load C.x into $t4
	lw	$t5, 20($s5)		# Load C.y into $t5
	
	sub	$t6, $t1, $t3		# $t6 = A.y - B.y
	mul	$t6, $t4, $t6		# $t6 *= C.x
	sub	$t7, $t5, $t1		# $t7 = C.y - A.y
	mul	$t7, $t2, $t7		# $t7 *= B.x
	sub	$t8, $t3, $t5		# $t8 = B.y - C.y
	mul	$t8, $t0, $t8		# $t8 *= A.x
	
	addu	$s3, $t6, $t7		# Sum the three registers into $s3
	addu	$s3, $s3, $t8

	addiu	$sp, $sp, -120		# Allocate space for 3 BresenhamLine structures on the stack
	
	# aToC = 0($sp)
	# bToC = 40($sp)
	# aToB = 80($sp)
	
	# Now call the constructor for aToC
	
	lw	$a0,  ($s0)		# Load A->x into $a0 (x0)
	lw	$a1, 4($s0)		# Load A->y into $a1 (y0)
	lw	$a2,  ($s2)		# Load C->x into $a2 (x1)
	lw	$a3, 4($s2)		# Load C->y into $a3 (y1)
	
	move	$t0, $sp		# Copy aToC to $t0
	addiu	$sp, $sp, -4		# Push pointer to aToC onto the stack
	jal	bline_ctor		# (with Branch Delay) Call the BresenhamLine structure constructor
	sw	$t0, ($sp)		# Branch Delay Slot: Push pointer to stack
	
	# Now call the constructor for bToC
	
	lw	$a0,  ($s1)		# Load B->x into $a0 (x0)
	lw	$a1, 4($s1)		# Load B->y into $a1 (y0)
	lw	$a2,  ($s2)		# Load C->x into $a2 (x1)
	lw	$a3, 4($s2)		# Load C->y into $a3 (y1)
	
	addiu	$t0, $sp, 40		# Calculate pointer to bToC
	addiu	$sp, $sp, -4		# Push pointer to bToC onto the stack
	jal	bline_ctor		# (with Branch Delay) Call the BresenhamLine structure constructor
	sw	$t0, ($sp)		# Branch Delay Slot: Push pointer to stack
	
	lw	$a1, 4($s0)		# Load A->y into $a1 (y0)
	lw	$a3, 4($s1)		# Load B->y into $a3 (y1)
	
	beq	$a1, $a3, .ft_initloop2	# If the y values of A and B are equal, we can skip the first drawing loop and constructor for aToB, otherwise:
	nop
	
	# Now call the constructor for aToB (parameters y0, and y1 are already loaded)
	
	lw	$a0, ($s0)		# Load A->x into $a0 (x0)
	lw	$a2, ($s1)		# Load B->x into $a2 (x1)
	
	addiu	$t0, $sp, 80		# Calculate pointer to aToB
	addiu	$sp, $sp, -4		# Push pointer to aToB onto the stack
	jal	bline_ctor		# (with Branch Delay) Call the BresenhamLine structure constructor
	sw	$t0, ($sp)		# Branch Delay Slot: Push pointer to stack
	
	# Drop through to the first loop initializer
	
.ft_initloop1:				# Loop along lines aToB and aToC
	addiu	$s0, $sp, 80		# Set "loop line 1 pointer" to aToB
	addiu	$s1, $sp, 0		# Set "loop line 2 pointer" to aToC
	j	.ft_loop		# (with Branch Delay) Run the drawing loop
	li	$s2, 1			# Branch Delay Slot: Set "is first loop flag" to true
	
.ft_initloop2:				# Loop along lines aToC and bToC
	addiu	$s0, $sp, 0		# Set "loop line 1 pointer" to aToC
	addiu	$s1, $sp, 40		# Set "loop line 2 pointer" to bToC
	li	$s2, 0			# Set "is first loop flag" to false
	
	# Drop through into the drawing loop
.ft_loop:
	jal	bline_getnext		# (with Branch Delay) Call bline_getnext
	move	$a0, $s0		# Branch Delay Slot: Call bline_getnext for the first line (move $s0 into $a0)
	
	bnez	$a1, .ft_breakloop	# Break loop if bline_getnext returned true (in $a1)
	nop
	move	$s4, $v0		# Save the x component for later
	
	jal	bline_getnext		# (with Branch Delay) Call bline_getnext
	move	$a0, $s1		# Branch Delay Slot: Call bline_getnext for the second line (move $s1 into $a0)
	
	bnez	$a1, .ft_breakloop 	# Break loop if bline_getnext returned true (in $a1)
	nop
	
	# Now call drawhline
	move	$a0, $s4		# Setup x0 argument (use the first line's result)
	move	$a1, $v0		# Setup x1 argument (use the second line's result)
	move	$a2, $v1		# Setup y argument (either line will do, but $v1 already contains y from the second line)
	move	$a3, $s3		# Setup uvDenominator argument
	addiu	$sp, $sp, -12
	sw	$s7, ($sp)		# Push mode to the stack
	sw	$s5, 4($sp)		# Push points array to stack
	jal	filltriangle_drawhline	# (with Branch Delay) Call drawhline
	sw	$s6, 8($sp)		# Branch Delay Slot: Push colour / colours pointer to stack
	
	j	.ft_loop		# Loop
	nop
	
.ft_breakloop:
	beqz	$s2, .ft_enddraw	# If this was the second loop, we're done, stop drawing
	nop
					# This was the first loop.
	jal	bline_getnext		# (with Branch Delay) This will realign bToC with aToC, otherwise it will be 1 y value out.
	addiu	$a0, $sp, 40		# Branch Delay Slot: Make a dummy call to bline_getnext for bToC
	
	j	.ft_initloop2		# Jump to the 2nd loop initializer
	nop
	
.ft_enddraw:
	addiu	$sp, $sp, 120		# Deallocate the 3 BresenhamLine structures from the stack
	
.ft_exit:
	lw	$s0,  0($sp)		# Restore $s0
	lw	$s1,  4($sp)		# Restore $s1
	lw	$s2,  8($sp)		# Restore $s2
	lw	$s3, 12($sp)		# Restore $s3
	lw	$s4, 16($sp)		# Restore $s4
	lw	$s5, 20($sp)		# Restore $s5
	lw	$s6, 24($sp)		# Restore $s6
	lw	$s7, 28($sp)		# Restore $s7
	lw	$ra, 32($sp)		# Restore $ra
	jr	$ra			# (with Branch Delay) Return
	addiu	$sp, $sp, 36		# Branch Delay Slot: Adjust the stack pointer
	
# struct BresenhamLine
# {
#     // Field	    Offset
#     int x0;		 0
#     int y0;		 4
#     int x1;		 8
#     int y1;		12
#     int sx;		16
#     int sy;		20
#     int err;		24
#     int dx;		28
#     int dy;		32
#     bool done;	36
# }	

# Function: void bline_ctor(int x0, int y0, int x1, int y1, BresenhamLine* pLine)
#
# This function acts as the constructor for a BresenhamLine structure.
# It initializes the values in the BresenhamLine structure pointed to by pLine.
#
# Usage:
#
# $a0 = x0
# $a1 = y0
# $a2 = x1
# $a3 = y1
# ($sp) = pLine
#
# Returns:
#
# *none*
#
# Local Variables Used:
#
# $t0 = pLine
# $t1 = general temp
# $t8 = dx
# $t9 = dy
#
bline_ctor:
	lw	$t0, ($sp)		# Load the pLine pointer into $t0
	
	sw	$a0,   ($t0)		# Save x0 to the structure
	sw	$a1,  4($t0)		# Save y0 to the structure
	sw	$a2,  8($t0)		# Save x1 to the structure
	sw	$a3, 12($t0)		# Save y1 to the structure
	
	subu	$t8, $a2, $a0		# Calculate x1 - x0, save in $t8
	abs	$t8, $t8		# Get absolute value of $t8
	sw	$t8, 28($t0)		# Save dx to the structure
	
	subu	$t9, $a3, $a1		# Calculate y1 - y0, save in $t9
	abs	$t9, $t9		# Get absolute value of $t9
	sw	$t9, 32($t0)		# Save dy to the structure
	
					# Calculate sx
	slt	$t1, $a0, $a2		# If x0 < x1, set $t1 to 1, otherwise 0
	sll	$t1, $t1, 1		# Multiply result by 2
	addiu	$t1, $t1, -1		# Decrement result
	sw	$t1, 16($t0)		# Save sx to the structure
	
					# Calculate sy
	slt	$t1, $a1, $a3		# If y0 < y1, set $t1 to 1, otherwise 0
	sll	$t1, $t1, 1		# Multiply result by 2
	addiu	$t1, $t1, -1		# Decrement result
	sw	$t1, 20($t0)		# Save sy to the structure
	
					# Calculate err
	subu	$t1, $t8, $t9		# $t1 = dx - dy
	sw	$t1, 24($t0)		# Save err to the structure
	
	li	$t1, 0
	sw	$t1, 36($t0)		# Set done flag to 0
	
	jr	$ra			# (with Branch Delay) Return
	addiu	$sp $sp, 4		# Branch Delay Slot: Pop pLine from the stack
	
# Function: (int x, int y) bline_getnext(BresenhamLine* pLine, out bool done)
#
# This function operates on a BresenhamLine structure to return the next
# x and y coordinates of the line. Values in the structure pointed to
# by pLine are updated to maintain state.
# If the line is completed, $a1 is set to true (non-zero), otherwise false (zero).
#
# Usage:
#
# $a0 = pLine
#
# Returns:
#
# $v0 = x
# $v1 = y
# $a1 = done boolean
#
# Local Variables Used:
#
# $t0 = x0 / temp boolean
# $t1 = y0
# $t2 = y1
# $t3 = err
# $t4 = e2
# $t5 = -dy
# $t6 = dx
# $t7 = sx
# $t8 = sy
#
bline_getnext:
	lw	$t0, 36($a0)			# Check the done flag
	
	beqz	$t0, .blgn_notdone		# Continue if we are not done
	nop
	li	$a1, 1				# Otherwise, return true
	jr	$ra				# Return
	nop
	
.blgn_notdone:
	lw	$t0,   ($a0)			# Load pLine->x0 into $t0
	lw	$t1,  4($a0)			# Load pLine->y0 into $t1
	move	$v0, $t0			# Copy pLine->x0 into result x
	move	$v1, $t1			# Copy pLine->y0 into result y
	
	lw	$t2, 12($a0)			# Load pLine->y1 into $t2
	bne	$t1, $t2, .blgn_ynotequal	# If y0 != y1, continue, otherwise:
	nop
	
	lw	$v0,  8($a0)			# Load pLine->x1 into result x
	li	$t0, 1				# Save pLine->done = true
	sw	$t0, 36($a0)
	
	li	$a1, 0				# But this time, return false
	jr	$ra				# Return
	nop
	
.blgn_ynotequal:
	lw	$t3, 24($a0)			# Load pLine->err into $t3
	lw	$t6, 28($a0)			# Load pLine->dx into $t6
	lw	$t5, 32($a0)			# Load pLine->dy into $t5
	lw	$t7, 16($a0)			# Load pLine->sx into $t7
	lw	$t8, 20($a0)			# Load pLine->sy into $t8
	
	subu	$t5, $zero, $t5			# Negate dy
	
.blgn_loop:
	sll	$t4, $t3, 1			# Multiply err by 2, store in e2 ($t4 = $t3 * 2)
	
	ble	$t4, $t5, .blgn_skipxadjust	# If e2 <= -dy, skip x adjustment, otherwise:
	nop
	addu	$t3, $t3, $t5			# err = err + (-dy)
	addu	$t0, $t0, $t7			# x0 = x0 + sx
	
.blgn_skipxadjust:
	bge	$t4, $t6, .blgn_loop		# If e2 >= dx, skip y adjustment (continue the loop), otherwise:
	nop
	
	addu	$t3, $t3, $t6			# err = err + dx
	j	.blgn_breakloop			# Break out of loop (with delay slot)
	addu	$t1, $t1, $t8			# Branch Delay Slot: y0 = y0 + sy
	
.blgn_breakloop:
	sw	$t0,   ($a0)			# Save x0 back to pLine->x0
	sw	$t1,  4($a0)			# Save y0 back to pLine->y0
	sw	$t3, 24($a0)			# Save err back to pLine->err
	
	li	$a1, 0				# We are not complete, return false
	jr	$ra				# Return
	nop
	
# Function: filltriangle_drawhline(int x0, int x1, int y, int uvDenominator, int mode, ...)
#
# This function draws a horizontal line  from (x0, y) to (x1, y).
# The colour of each pixel is determined by the shading model selected by the mode value.
# The arguments do not need to be sorted by x coordinate.
#
# Usage:
# 
# $a0 = x0
# $a1 = x1
# $a2 = y
# $a3 = uvDenominator
# ($sp) = mode
# 4($sp) = Point points[3]
# 8($sp) = Colour colours[3] / Colour colour
#
# Returns:
# 
# *none*
# 
# Local Variables Used:
#
# $t1 = scrn_width
# $t2 = scrn_height
# $t3 = swap register / points array pointer
# $t4 = bitmap display pointer
# $t5 = u
# $t6 = v
# $t7 = t
# $t8 = uv calc reg 1
# %t9 = uv calc reg 2
# $t0 = ub calc reg 3
# $v0 = y copy
#
# $s0 = output pixel colour
# $s1 = mode
# $s2 = shader function pointer
# $s3 = colour / colour pointer copy
#
filltriangle_drawhline:
	addiu	$sp, $sp, -20			# Save registers to the stack
	sw	$ra, 16($sp)			# Save $ra
	sw	$s3, 12($sp)			# Save $s3
	sw	$s2,  8($sp)			# Save $s2
	sw	$s1,  4($sp)			# Save $s1
	sw	$s0,   ($sp)			# Save $s0

	lw	$s1, 20($sp)			# Load mode from stack
	lw	$s3, 28($sp)			# Load colour / colour pointer from stack
	move	$v0, $a2			# Copy y value to $v0
	
	bne	$s1, 1, .ftdhl_notmode1		# Is this mode 1??
	nop
	la	$s2, .ftdhl_uvgrad		# Load pointer to the shader function
	j	.ftdhl_modeset
	nop
	
.ftdhl_notmode1:
	bne	$s1, $zero, .ftdhl_exit		# Last mode is 0, if not 0 exit
	nop
	li	$s2, 0				# Set function pointer to 0
	move	$s0, $s3			# Copy colour value into $s0

.ftdhl_modeset:

	lw	$t2, scrn_height		# Load scrn_height into $t2
	bge	$a2, $t2, .ftdhl_exit		# If y >= scrn_height, exit (cannot draw off the screen)
	nop
	bltz	$a2, .ftdhl_exit		# If y < 0, exit (cannot draw off the screen)
	nop
	
	bge	$a1, $a0, .ftdhl_skipswap 	# If x1 >= x0, skip the x0<->x1 swap, otherwise:
	nop
	
	move	$t3, $a1			# Swap registers $a1 and $a0 (x0 <-> x1)
	move	$a1, $a0
	move	$a0, $t3
.ftdhl_skipswap:
	bgez	$a0, .ftdhl_skipx0clamp		# If x >= 0, skip x0 clamp, otherwise:
	nop
	li	$a0, 0				# Set x0 to 0
	
.ftdhl_skipx0clamp:
	lw	$t1, scrn_width			# Load scrn_width into $t1
	
	blt	$a1, $t1, .ftdhl_skipclamp	# If x1 < scrn_width, skip the clamp operation, otherwise:
	nop
	addiu	$a1, $t1, -1			# Set x1 = scrn_width - 1
.ftdhl_skipclamp:

	la	$t4, bitmapdisplay		# Load the bitmap display address into $t4
	mul	$a2, $a2, $t1			# $a2 = y * scrn_width
	addu	$a2, $a2, $a0			# $a2 += x0
	sll	$a2, $a2, 2			# Multiply index by 4
	addu	$t4, $t4, $a2			# bitmap display pointer += $a2
	
	lw	$t3, 24($sp)			# Load the points array pointer into $t3
	
.ftdhl_loop:
	bge	$a0, $a1, .ftdhl_exit		# If x0 > x1, exit drawhline
	nop
	
	beqz	$s2, .ftdhl_skipshader		# If there is no shader function, skip it, otherwise...
	nop
	jalr	$s2				# Call the shader function to adjust the colour value in $s0
	nop
	
.ftdhl_skipshader:
						# Colour value of pixel is now stored in $s0
	sw	$s0, ($t4)			# Write the pixel colour to the screen
	
	addiu	$t4, $t4, 4			# Increment bitmap display pointer by 1 pixel (4 bytes)
	j	.ftdhl_loop			# (with Branch Delay) Loop
	addiu	$a0, $a0, 1			# Branch Delay Slot: Increment x0
.ftdhl_exit:
	lw	$s0,   ($sp)			# Restore $s0
	lw	$s1,  4($sp)			# Restore $s1
	lw	$s2,  8($sp)			# Restore $s2
	lw	$s3, 12($sp)			# Restore $s3
	lw	$ra, 16($sp)			# Restore $ra
	jr	$ra				# (with Branch Delay) Return
	addiu	$sp, $sp, 32			# Branch Delay Slot: Adjust stack pointer to pop saved registers and arguments passed on the stack
	
#
# Shader function for gradient triangles
# Plugs into the filltriangle_drawhline function to adjust the $s0 pixel colour value
#
.ftdhl_uvgrad:
	# Calculate triangle u coordinate (integer value from 0 to 255)
	# Store in $t5
					# Calculate first bracket pair
	lw	$t8, 20($t3)		# Load C.y into $t8
	lw	$t9,  0($t3)		# Load A.x into $t9
	sub	$t0, $v0, $t8		# $t0 = y - C.y
	mul	$t5, $t9, $t0		# $t5 = A.x * (y - C.y)
	
					# Calculate second bracket pair
	lw	$t8,  4($t3)		# Load A.y into $t8
	lw	$t9, 16($t3)		# Load C.x into $t9
	sub	$t0, $t8, $v0		# $t0 = A.y - y
	mul	$t0, $t9, $t0		# $t0 = C.x * (A.y - y)
	
	add	$t5, $t5, $t0		# $t5 += $t0, Add second bracket pair to $t5
	
					# Calculate third bracket pair
					# A.y is already loaded in $t8
	lw	$t9, 20($t3)		# Load C.y into $t9
	sub	$t0, $t9, $t8		# $t0 = C.y - A.y
	mul	$t0, $a0, $t0		# $t0 *= x0
	
	add	$t5, $t5, $t0		# $t5 += $t0, Add third bracket pair to $t5
	
	mul	$t5, $t5, 255		# Multiply u value by 255 to prepare for division
	div	$t5, $a3		# Divide u value by the uvDenominator
	mflo	$t5
	
	bgez	$t5, .ftdhl_skipuclamp	# If u >= 0, don't clamp, otherwise...
	nop
	li	$t5, 0			# Clamp x to 0
.ftdhl_skipuclamp:
	
	# Calculate triangle v coordinate (integer value from 0 to 255)
	# Store in $t6
					# Calculate first bracket pair
	lw	$t8,  4($t3)		# Load A.y into $t8
	lw	$t9,  8($t3)		# Load B.x into $t9
	sub	$t0, $v0, $t8		# $t0 = y - A.y
	mul	$t6, $t9, $t0		# $t5 = B.x * (y - A.y)
	
					# Calculate second bracket pair
	lw	$t8, 12($t3)		# Load B.y into $t8
	lw	$t9,  0($t3)		# Load A.x into $t9
	sub	$t0, $t8, $v0		# $t0 = B.y - y
	mul	$t0, $t9, $t0		# $t0 = A.x * (B.y - y)
	
	add	$t6, $t6, $t0		# $t6 += $t0, Add second bracket pair to $t6
	
					# Calculate third bracket pair
					# B.y is already loaded in $t8
	lw	$t9,  4($t3)		# Load A.y into $t9
	sub	$t0, $t9, $t8		# $t0 = A.y - B.y
	mul	$t0, $a0, $t0		# $t0 *= x0
	
	add	$t6, $t6, $t0		# $t6 += $t0, Add third bracket pair to $t6
	
	mul	$t6, $t6, 255		# Multiply v value by 255 to prepare for division
	div	$t6, $a3		# Divide v value by the uvDenominator
	mflo	$t6
	
	bgez	$t6, .ftdhl_skipvclamp	# If v >= 0, don't clamp, otherwise...
	nop
	li	$t6, 0			# Clamp v to 0
.ftdhl_skipvclamp:
	
	# Calculate triangle t coordinate (integer value from 0 to 255)
	# Store in $t7
	
	li	$t7, 255		# t = 255
	sub	$t7, $t7, $t5		# t -= u
	sub	$t7, $t7, $t6		# t -= v
	
	# Calculate Pixel Colour
	
	# Calculate Red component
	lbu	$t9, 5($s3)		# Load first colour's red into $t9
	mul	$t0, $t5, $t9		# Multiply 1st red by u
	lbu	$t9, 9($s3)		# Load 2nd colour's red into $t9
	mul	$t8, $t6, $t9		# Multiply 2nd red by v
	addu	$t0, $t0, $t8		# Add the two values
	lbu	$t9, 1($s3)		# Load third colour's red into $t9
	mul	$t9, $t7, $t9		# Multiply 3rd red by t
	addu	$t0, $t0, $t9		# Add the two values
	div	$s0, $t0, 255		# Divide value by 255 and store in $s0
	sll	$s0, $s0, 16		# Shift red value into 3rd byte
	
	# Calculate Green component
	lbu	$t9, 6($s3)		# Load first colour's green into $t9
	mul	$t0, $t5, $t9		# Multiply 1st green by u
	lbu	$t9, 10($s3)		# Load 2nd colour's green into $t9
	mul	$t8, $t6, $t9		# Multiply 2nd green by v
	addu	$t0, $t0, $t8		# Add the two values
	lbu	$t9, 2($s3)		# Load third colour's green into $t9
	mul	$t9, $t7, $t9		# Multiply 3rd green by t
	addu	$t0, $t0, $t9		# Add the two values
	div	$t0, $t0, 255		# Divide value by 255
	sll	$t0, $t0, 8		# Shift green value into second byte
	or	$s0, $s0, $t0		# OR green into colour register
	
	# Calculate Blue component
	lbu	$t9, 7($s3)		# Load first colour's red into $t9
	mul	$t0, $t5, $t9		# Multiply 1st red by u
	lbu	$t9, 11($s3)		# Load 2nd colour's red into $t9
	mul	$t8, $t6, $t9		# Multiply 2nd red by v
	addu	$t0, $t0, $t8		# Add the two values
	lbu	$t9, 3($s3)		# Load third colour's red into $t9
	mul	$t9, $t7, $t9		# Multiply 3rd red by t
	addu	$t0, $t0, $t9		# Add the two values
	div	$t0, $t0, 255		# Divide value by 255
	jr	$ra			# (with Branch Delay) Return
	or	$s0, $s0, $t0		# Branch Delay Slot: OR blue into colour register