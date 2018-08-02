using UnityEngine;
using System.Collections;

public class playerSphere : MonoBehaviour {
    float jump_speed = 5.0f;
	// Use this for initialization
	void Start () {
        GetComponent<Rigidbody>().velocity = new Vector3(0, -5, 0);
	}
	
	// Update is called once per frame
	void Update () {
	}
    void OnBecameInvisible()
    {
        Destroy(gameObject);
    }
}
