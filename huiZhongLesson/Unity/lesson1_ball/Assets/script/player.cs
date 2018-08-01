using UnityEngine;
using System.Collections;

public class player : MonoBehaviour {
    float jump_speed = 5.0f;
    bool is_landing = false;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	    if(Input.GetMouseButtonDown(0)&&is_landing){
            //GetComponent<Rigidbody>().velocity = Vector3.up * jump_speed;
            GetComponent<Rigidbody>().velocity = new Vector3(0,2,0)*jump_speed;
            is_landing = false;
        }
	}
    void OnCollisionEnter(Collision collision) {
        if (collision.gameObject.tag=="floor")
        {
         is_landing = true;
        }
       
    }
}
