using UnityEngine;
using System.Collections;

//携程和repeating
public class test : MonoBehaviour {

	// Use this for initialization
	void Start () {
        //InvokeRepeating("Printf",0.1f,3.0f);//每三秒打印一次名为Printf函数
        StartCoroutine(Test1());
	}
	
	// Update is called once per frame
	void Update () {
	
	}
    IEnumerator Test1() {
        while(true){
            Debug.Log("aaa");
            yield return new WaitForSeconds(2.0f);
            Debug.Log("ccc");
            yield return new WaitForSeconds(2.0f);
        }
    }
}
