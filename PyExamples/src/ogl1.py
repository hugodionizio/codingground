# Primeiro programa python OpenGL
# ogl1.py

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys

# Segundo programa python OpenGL
prog = 2
exer = '5e'

# Limites da janela
LARGURA = 400
ALTURA = 400
XPOS = (LARGURA + 100)/2
YPOS = 0

# Espessura da linha
WIRE_SIZE = 0.57

def draw():

	# Segundo programa python OpenGL
	if prog == 1.2 or prog == 2:
		glClear(GL_COLOR_BUFFER_BIT)

#	if WIRE_SIZE > 0.1: WIRE_SIZE -= 0.1

	if exer == 5: glutWireSphere(0.5, 10, 10) # Exercise 5
	elif exer == 4: glutWireTeapot(WIRE_SIZE) # Exercise 4
	elif exer == '5e': glutWireTetrahedron() # Exercise 5.e

	else: glutWireTeapot(0.5)
	glFlush()

glutInit(sys.argv)
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)

# Segundo programa python OpenGL
if prog == 2:
	if exer == 3: glutInitWindowSize(LARGURA,ALTURA) # Exercise 3

	else: glutInitWindowSize(250,250)
	glutInitWindowPosition(XPOS,YPOS)
	glutCreateWindow("Meu segundo programa OpenGL")
else:

	glutCreateWindow("Meu primeiro programa OpenGL")
glutDisplayFunc(draw)
glutMainLoop()

# Fim do programa
