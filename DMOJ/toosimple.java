package DMOJ;

enum HelloWorld {Hello, World};

public class Too_Simple {

	public static void main(String[] args) {
		String hello = HelloWorld.Hello.toString();
		String world = HelloWorld.World.toString();
		char whitespace = Integer.SIZE;
		char comma = Integer.SIZE + Byte.SIZE + Integer.BYTES; 
		char exclam = Integer.SIZE + Byte.BYTES;
		
		System.out.println(hello + comma + whitespace + world + exclam);
	}

}