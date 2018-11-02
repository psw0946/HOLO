<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

	<%
		String id = request.getParameter("id");
		String pw = request.getParameter("pw");
	%>
	
	아이디 : <%= id %><br />
	비밀번호 : <%= pw %>
	
	<hr/>
	
	아이디 : ${param.id }<br/>
	비밀번호 : ${param.pw }<br/>
	아이디 : ${param["id"] }<br/>
	비밀번호 : ${param["pw"] }<br/>
	
	<hr/>
	
	applicationScope : ${applicationScope.application_name }<br/>
	sessionScope : ${sessionScope.session_name }<br/>
	pageScope : ${pageScope.page_name }<br/>
	requestScope : ${requestScope.request_name }
	<!-- applicationScope은 그냥 여기 접속하는 모든... session은 브라우저마다 하나... -->
	<!-- pageScope과 requestScope은 page가 바뀌면서 scope이 달라지기 때문에 뜨지 않음. -->
	<hr/>
	
	context 초기화 파라미터<br/> <!-- xml에서 context-param -->
	${initParam.con_name }<br/>
	${initParam.con_id }<br/>
	${initParam.con_pw }<br/>
	
</body>
</html>