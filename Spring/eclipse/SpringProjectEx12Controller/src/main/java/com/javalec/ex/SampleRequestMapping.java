package com.javalec.ex;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/rm")
public class SampleRequestMapping {

	@RequestMapping("/view")
	public String view() {
		return "rm/view";
	}
	
	
}
