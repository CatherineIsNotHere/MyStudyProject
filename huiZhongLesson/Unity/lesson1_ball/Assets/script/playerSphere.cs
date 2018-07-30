using UnityEngine;
using System.Collections;

public class playerSphere : MonoBehaviour {
    float jump_speed = 5.0f;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetMouseButtonDown(1))
        {
            GetComponent<Rigidbody>().velocity = new Vector3(0, 1, 1) * jump_speed;
        }
	}
}
