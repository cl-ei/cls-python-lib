# -*- coding:utf-8 -*-
import os
import json
from wsgiserver.template import render
from wsgiserver.http import HttpResponse

from etc.config import PROJECT_ROOT, PARSED_ARTICLE_JSON


def favicon_response(request):
    with open("static/img/favicon.png", "rb") as f:
        content = f.read()
    return HttpResponse(content, content_type="image/x-icon")


def home_page(request):
    article_file_path = os.path.join(PROJECT_ROOT, PARSED_ARTICLE_JSON)
    article_js_file_name = os.listdir(article_file_path)[0]
    article_js = os.path.join(PARSED_ARTICLE_JSON, article_js_file_name)
    context = {
        "article_js": article_js,
        "page": {
            "author": "CL",
            "description": "CL����̰����ߣ�����CL�Ĺٷ����ͣ���¼��������ѧϰ��Ρ�",
            "keywords": "MADLIAR, CL, CL's ���Է���, ���Է���, ���Է���, CL����",
        },
    }
    return render(
        "template/home_page.html",
        context=context
    )


def record(request):
    # TODO: add ...
    return HttpResponse(json.dumps({"err_code": 0}), content_type="application/json")
