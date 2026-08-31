import java.util.*;
import java.lang.*;
public class Main{
	private static int find(int[] ldr,int node){
		if(!(ldr[node]==node)) ldr[node]=find(ldr,ldr[node]);
		return ldr[node];
	}
	private static void join(int[] ldr,int lt,int rt){
		ldr[find(ldr,rt)]=find(ldr,lt);
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int nof=sc.nextInt();
		int existf=sc.nextInt();
		int[][] edges=new int[existf][2];
		int[] ldr=new int[nof+1];
		for(int node=1;node<=nof;node++) ldr[node]=node;
		for(int i=0;i<existf;i++){
			edges[i][0]=sc.nextInt(); edges[i][1]=sc.nextInt();
			join(ldr,edges[i][0],edges[i][1]);
		}
		int[] gcnt=new int[nof+1];
		int[] ecnt=new int[nof+1];
		for(int node=1;node<=nof;node++){
			gcnt[find(ldr,node)]++;
		}
		for(int[] elem:edges){
			ecnt[find(ldr,elem[0])]++;
		}
		long ans=0;
		for(int node=1;node<=nof;node++){
			long curr=(1L*gcnt[node]*(gcnt[node]-1)/2)-ecnt[node];
			ans+=curr;
		}
		System.out.println(ans);
	}
}