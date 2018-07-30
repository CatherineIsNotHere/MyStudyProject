using UnityEngine;
using System.Collections;

public class player : MonoBehaviour {
    float jump_speed = 5.0f;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	    if(Input.GetMouseButtonDown(0)){
            //GetComponent<Rigidbody>().velocity = Vector3.up * jump_speed;
            GetComponent<Rigidbody>().velocity = new Vector3(0,1,0)*jump_speed;
        }
       
	}
}
