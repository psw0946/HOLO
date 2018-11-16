package com.javalec.ex;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class MyController {
	
	@RequestMapping("/board/modelEx")
	public String modelEx(Model model) {
		model.addAttribute("data", "abcdefghi");
		
		return "board/modelEx";
	}
	
	@RequestMapping("/board/modelView")
	public ModelAndView modelAndView() {
		ModelAndView mv = new ModelAndView();
		mv.addObject("id", "abcde");
		mv.setViewName("board/modelAndView");
		
		return mv;
	}
}
