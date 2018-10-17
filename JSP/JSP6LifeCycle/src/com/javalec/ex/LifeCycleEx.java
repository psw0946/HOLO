package com.javalec.ex;

import java.io.IOException;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class LifeCycleEx
 */
@WebServlet("/LC")
public class LifeCycleEx extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public LifeCycleEx() {
        super();
        // TODO Auto-generated constructor stub
    }
    
    @Override // 서버 처음 열릴 때 딱 한 번 실행
    public void init() throws ServletException {
    	// TODO Auto-generated method stub
    	System.out.println("init");
    }
    
    @Override // 서버 닫힐 때 딱 한 번 실행
    public void destroy() {
    	// TODO Auto-generated method stub
    	System.out.println("destroy");
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		System.out.println("doGet");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		System.out.println("doPost");
	}

	@PostConstruct // init 전에 제일 먼저 실행하는
	private void initPostConstruct() {
		System.out.println("initPostConstruct");
	}
	
	@PreDestroy // destroy 후에 제일 마지막으로 실행하는
	private void destroyPreDestroy() {
		System.out.println("destroyPreDestroy");
	}
}
