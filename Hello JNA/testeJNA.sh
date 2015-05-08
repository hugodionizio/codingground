# Criação da Pasta de binários "bin"
mkdir bin

# Compilação e verificação da biblioteca em C
gcc -fPIC -c src/ctest.c
gcc -shared -o bin/libctest.so ctest.o
rm ctest.o
nm bin/libctest.so

# Importação da biblioteca jna.jar
cp src/jna.jar bin/jna.jar
cd bin/
jar xvf jna.jar com/
rm jna.jar
cd ..

# Compilação do projeto em Java
javac -classpath src/jna.jar src/HelloWorld.java -d bin/
cp -r src/META-INF bin/META-INF
cd bin
jar cvfm HelloJNA.jar META-INF/MANIFEST.MF HelloWorld.class HelloWorld\$CTest.class com libctest.so

# Execução do projeto em jar
java -jar HelloJNA.jar
