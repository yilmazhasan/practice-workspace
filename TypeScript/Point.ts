export class Point{
	//access modifires are public by default
	private x: number;
	private y: number;
	public z: number;
	
	constructor(x?: number, y?:number, z?:number){ //? makes param optional
		this.x = x;
		this.y = y || -1;
		this.z = z;
	}
	
	draw(){ 
		console.log("X: " + this.x + " Y: " + this.y + " Z: " + this.z)		
	}
	
}

